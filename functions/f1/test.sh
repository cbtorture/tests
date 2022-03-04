#!/bin/python3

# Compiler list
compilers=[
		"gcc",
		"clang",
		"ccomp",
		"tcc"
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

def comp(compiler, option, std, file):
	resFile=open("/tmp/res","w")
	import subprocess

	args=[compiler, file]

	# If ccomp no std (no aids)
	if compiler != "ccomp":
	    args+=["-std="+std]
	else:
		std="Default"

	args+=[option]


	args+=["-o", "/tmp/resBin"]
	
	subprocess.run(args, cwd=".")

	import os

	result=str.strip(subprocess.getoutput("/tmp/resBin"))

	observation=""

	if int(result) == 5:
		observation="right-to-left execution ordering"
	elif int(result) == 4:
		observation="left-to-right execution ordering"

	output=""
	output="| %s | %s | %s | `%s` |" % (compiler, option, std, result)
	output+=""+observation+" |"

	return output

def test(file):
	print("Running: %s"%file)
	print()
	output="| Compiler | Options| Standard | `result` | Observation |\n"
	output+="|----|----|----|---|---|"+"\n"
	for compiler in compilers:
		for option in options:
		    for std in stds:
			    output+=comp(compiler, option, std, file)+"\n"

	print(output)

test("program.c")
