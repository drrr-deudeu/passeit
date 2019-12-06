import glob

for i in glob.glob("*.c"):
    f = open(i,"r")
    lines = f.readlines();
    s = 0
    count = 0
    for l in lines:
        if l[0] == "{":
            s += 1
            count = 0
        elif l[0] == "}":
            s -= 1
            if (s == 0):
                print "in", i, count
        else:
            count += 1
                
