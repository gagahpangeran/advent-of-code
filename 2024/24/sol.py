from sys import stdin
from graphviz import Digraph


def tabprint(somd):
    for idx, (key, val) in enumerate(sorted(somd.items())):
        sep = '\n' if idx % 10 == 9 else ', '
        print(f"{key}: {val}", end=sep)
    print()


get_input = True

values = {}
gates = []

done = []


for s in stdin:
    s = s.strip()

    if len(s) == 0:
        get_input = False
        continue

    if get_input:
        wire, val = s.split(": ")
        values[wire] = int(val)
    else:
        gate, owire = s.split(" -> ")
        wire1, ops, wire2 = gate.split(" ")
        gates.append((wire1, wire2, ops, owire))


def get_val(char):
    return int(''.join([str(i) for _, i in sorted(
        [(wire, val) for wire, val in values.items() if wire[0] == char], reverse=True
    )]), 2)


while len(gates) != len(done):
    for gate in gates:
        if gate in done:
            continue

        wire1, wire2, ops, owire = gate
        if wire1 in values and wire2 in values:
            if ops == "AND":
                values[owire] = values[wire1] & values[wire2]
            elif ops == "OR":
                values[owire] = values[wire1] | values[wire2]
            elif ops == "XOR":
                values[owire] = values[wire1] ^ values[wire2]

            done.append(gate)

res = get_val("z")
print(res)

# Code to visualize the circuit.
# Basically this is just 45 bit full adder.
circuit = Digraph(format='png')

for input1, input2, gate_type, output in gates:
    circuit.node(input1, input1, shape='circle')
    circuit.node(input2, input2, shape='circle')
    circuit.node(output, output, shape='circle')
    circuit.node(f"{output}_GATE", gate_type, shape='box')

    circuit.edge(input1, f"{output}_GATE")
    circuit.edge(input2, f"{output}_GATE")
    circuit.edge(f"{output}_GATE", output)

circuit.render('circuit')

# This is the result after looking at the circuit
# and find the "wrong" wiring manually.
sol = ["z06", "vwr", "z11", "tqm", "z16", "kfs", "gfv", "hcm"]
print(','.join(sorted(sol)))
