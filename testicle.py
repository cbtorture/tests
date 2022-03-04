#!/bin/python3

"""
General tester
"""

class Verifier:
    def __init__(self, commands):
        self.commands = commands

    def verify(self, filePath, expectedAssertion):
        return True

    def __str__(self):
        return self.__class__.__name__

class GCC(Verifier):
    def __init__(self, commands):
        self.commands = ["gcc"]+commands

    def verify(self, filePath, expectedAssertion):
        import subprocess
        
        # Compile firstly
        subprocess.run(self.commands+[filePath],stdout=open("/dev/null"))

        # Execute the binary
        info = subprocess.run(["./a.out"],cwd=".", shell=True,stderr=open("/dev/null"))
        exitCode = info.returncode

        if exitCode == 0:
            return True
        else:
            return False

class Clang(Verifier):
    def __init__(self, commands):
        self.commands = ["clang"]+commands

    def verify(self, filePath, expectedAssertion):
        import subprocess
        
        # Compile firstly
        subprocess.run(self.commands+[filePath],stdout=open("/dev/null"))

        # Execute the binary
        info = subprocess.run(["./a.out"],cwd=".", shell=True, stderr=open("/dev/null"))
        exitCode = info.returncode

        if exitCode == 0:
            return True
        else:
            return False

class TCC(Verifier):
    def __init__(self, commands):
        self.commands = ["tcc"]+commands

    def verify(self, filePath, expectedAssertion):
        import subprocess
        
        # Compile firstly
        subprocess.run(self.commands+[filePath],stdout=open("/dev/null"))
        
        # Execute the binary
        info = subprocess.run(["./a.out"],cwd=".", shell=True,stderr=open("/dev/null"))
        exitCode = info.returncode

        if exitCode == 0:
            return True
        else:
            return False

class CBMC(Verifier):
    def __init__(self):
        self.commands=["cbmc"]

    def verify(self, filePath, expectedAssertion):
        import subprocess
        
        # Execute the binary
        info = subprocess.run(self.commands+[filePath],cwd=".", stdout=open("/dev/null"), stderr=open("/dev/null"))
        exitCode = info.returncode

        if exitCode == 0:
            return True
        else:
            return False

class ESBMC(Verifier):
    def __init__(self):
        self.commands=["esbmc"]

    def verify(self, filePath, expectedAssertion):
        import subprocess
        
        # Execute the binary
        info = subprocess.run(self.commands+[filePath],cwd=".", stdout=open("/dev/null"),stderr=open("/dev/null"))
        exitCode = info.returncode

        if exitCode == 0:
            return True
        else:
            return False

verifiers=[
]

verifiers.append(CBMC())
verifiers.append(ESBMC())

"""
Compilers all really share some of the same flags.

Atleast these do, so generate verifiers with these flags

1. clang
2. gcc
3. tcc
"""
def fillUpCompilers():
    # List of options to try
    options=[
    		"-O0",
    		"-O1",
    		"-O2",
    		"-O3",
    ]
    
    # List of standards
    stds=[
            "c99",
            "c9x",
            "c89",
            "c90",
            "c2x",
            "c17",
            "c18",
            "c11",
            "c1x",
            "gnu11",
            "iso9899:1990",
            "iso9899:199409",
            "gnu89",
            "gnu90",
            "iso9899:1999",
            "gnu99",
            "iso9899:2011",
            "iso9899:2017",
            "gnu11"
        ]

    for option in options:
        for std in stds:
            verifier=GCC(["-std=%s"%std, option])
            verifiers.append(verifier)

            verifier=Clang(["-std=%s"%std, option])
            verifiers.append(verifier)

            verifier=TCC(["-std=%s"%std, option])
            verifiers.append(verifier)


fillUpCompilers()


def verifyFile(path, expectedAssertion, reportFile):
    print("Running tests for program '%s' with assertion (%s)..."%(path, expectedAssertion))

    report=""
    report+="Running program: %s"%path
    report+="\n"
    report+="Expected assetion: %s"%expectedAssertion
    report+="\n"
    report+="| Verifier | Arguments | Assertion expected | Assertion result |"
    report+="| --- | --- | --- | --- |"
    for verifier in verifiers:
        result = verifier.verify(path, expectedAssertion)

        if result == True:
            result="✅️"
        else:
            result="❌️"
            

        report+="|"+str(verifier) + "| "+str(verifier.commands) +"| "+expectedAssertion+"| "+result  + "|"

    f=open(reportFile,"w")
    f.write(report)
    f.close()

#verifyFile("test.c", "1==1")

#F1 (left-to-right test)
verifyFile("functions/f1/program_analysis.c", "result == 4", "f1_lr_report.md")

#F1 (right-to-left test)
# TODO: Can disable as only one other permutation exists
verifyFile("functions/f1/program_analysis2.c", "result == 5", "f1_rl_report.md")

#F2 (left-to-right test)
verifyFile("functions/f2/program_analysis.c", "result == 11", "f2_rl_report.md")

#F2 (right-to-left test)
# TODO: Can disable as only one other permutation exists
verifyFile("functions/f2/program_analysis2.c", "result == 13", "f2_lr_report.md")


#L1 (left-to-right)
verifyFile("lists/l1/program_analysis.c", "result[0] == 1 && result[1] == 2", "l1_lr_report.md")

#L1 (right-to-left test)
# TODO: Can disbale as only one other permutation exists
verifyFile("lists/l1/program_analysis2.c", "result[0] == 2 && result[1] == 1", "l1_rl_report.md")