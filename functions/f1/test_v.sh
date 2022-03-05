#!/bin/python3

# Verifier list
verifiers=[
		"cbmc",
		"esbmc"
]

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
        "gnu17"
]

# Results
results={}

def comp(compiler, option, std, file, expectedAssertion):
	resFile=open("/tmp/res","w")
	import subprocess

	args=[compiler, file]

	
	#args+=["-o", "/tmp/resBin"]
	
	result=subprocess.run(args, cwd=".").returncode
	print(result)

	import os

	#result=str.strip(subprocess.getoutput(compiler+" "+file))

	observation=""

	if int(result) == 0:
		observation="✅️"
	else:
		observation="❌️"
	output=""
	output="| %s | %s | %s | `%s` | `%s` |" % (compiler, option, std, result, expectedAssertion)
	output+=""+observation+" |"

	return output

def test(file, expectedAssertion):
	print("Running: %s"%file)
	print()
	output="| Verifier | Options| Standard | `exit code` | Observation | Expected assertion|\n"
	output+="|----|----|----|---|---|---|"+"\n"
	for verifier in verifiers:
		#for option in options:
		#    for std in stds:
				#output+=comp(verifier, option, std, file, expectedAssertion)+"\n"
		#		pass
		output+=comp(verifier, [], "", file,expectedAssertion)+"\n"

	return output

output=test("program_analysis.c", "assert(result == 4);")
output+="\n\n"+test("program_analysis2.c", "assert(result == 5);")
print(output)
