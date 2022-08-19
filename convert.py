#!/usr/bin/python

import sys, re


TYPES = ["int", "char", "size_t", "void", "List", "Item", "Node", "unsigned int"]
OPS = ["if", "while", "switch", "case", "default", "else", "try", "catch", "break", "return"]

with open(sys.argv[1], 'r') as inf:
    with open("converted.txt", 'w') as outf:
        for default in inf:
            leading = len(default) - len(default.lstrip())
            line = default.strip()
            for type in TYPES:
                result = re.match(f"{type}", line)
                if result:
                    match = re.search("\(", line)
                    if match:
                        final = re.match("(.*)\{", line).group(1)
                        outf.writelines(f"\nFUNCTION {final}\n")
                        break
                    final = re.match("(.*);", line).group(1)
                    outf.writelines(f"{' ' * leading}DECLARE {final}\n")
                    break
            else:
                for statement in OPS:
                    result = re.match(f"{statement}", line)
                    if result:
                        final = re.match(f"{statement}([\s\S]*)$", line).group(1)
                        outf.writelines(f"{' ' * leading}{statement.upper()} {final}\n")
                        break
                else:
                    result = re.match("}", line)
                    if result:
                        outf.writelines(f"{' ' * leading}{line}\n")
                        continue
                    result = re.match("std::cout", line)
                    if result:
                        final = re.match("std::cout([\s\S]*)$", line).group(1)
                        outf.writelines(f"{' ' * leading}DISPLAY {final}\n")
                        continue
                    result = re.match(".", line)
                    if result:
                        outf.writelines(f"{' ' * leading}CALL {line}\n")
                        continue

