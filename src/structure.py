from glob import glob
import os


elements = glob("./**/examples/*")

# print(elements)

for el in elements:
    os.system("cp -r " + el + " " + "./examples/")
    print("Done: " + el)
        