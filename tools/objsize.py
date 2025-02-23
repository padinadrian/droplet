import os
import glob

for i in range(0, 4):
    objfiles = glob.glob("build/**/*.{}.o".format(i), recursive=True)
    total = sum([os.path.getsize(f) for f in objfiles])

    print("{}: {}".format(i, total))
    for f in objfiles:
        print("\t", os.path.getsize(f), "-", f)


