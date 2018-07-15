import sys
import os

# store file path from command line arguments.
in_file = sys.argv[1]

# print error if file doesn't exist.
if not os.path.exists(in_file):
	print("Error : Invalid or NULL file path in command line argument.")

# read file lines in list.
with open(in_file) as f:
    log_lines = f.readlines()
	
# Remove whitespace characters like `\n` at the end of each line
log_lines = [line.strip() for line in log_lines]

out_fileptr = open(in_file, 'w')

for item in log_lines:
	wordlist = item.split(":")
	del wordlist[1]		#delete path string
	item = ":".join(wordlist)
	print(item)
	out_fileptr.write(item + '\n')
	
out_fileptr.close()