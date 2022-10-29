import sys

string = sys.stdin.readline().strip()
cmd_count = int(sys.stdin.readline().strip())
cursor = []

for _ in range(cmd_count):
    cmd = sys.stdin.readline().strip()
    if cmd == "L":
        if len(string) == 0: continue
        cursor.append(string[len(string)-1])
        string = string[0:len(string)-1]

    elif cmd == "D":
        if len(cursor) == 0: continue
        string += cursor.pop()

    elif cmd == "B":
        if len(string) == 0: continue
        string = string[:len(string)-1]

    else:
        cmd = cmd.replace(" ","")
        char = cmd[1:]
        string += char

cursor = cursor[::-1]
cursor = "".join(cursor)
print(string + cursor)