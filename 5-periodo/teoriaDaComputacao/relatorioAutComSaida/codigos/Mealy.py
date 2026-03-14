from automata.fa.Mealy import Mealy
from sys import argv

mealy = Mealy(['q0', 'q1', 'q2', 'q3'],
              ['a', 'b'],
              ['0', '1'],
              {
                'q0': {'a': ('q0', '1'), 'b': ('q1', ''), 'c': ('q2', '2')},
                'q1': {'a': ('q0', '1'), 'b': ('q1', ''), 'c': ('q2', '2')},
                'q2': {'a': ('q0', '1'), 'b': ('q1', ''), 'c': ('q2', '2')},
              },
              'q0'
              )

              
print(mealy)
print(mealy.get_output_from_string('aaabbbccc'))

if __name__ == "__main__":
  if len(argv) < 2 :
    raise IOError("Use Mealy.py file.cm")
  else :
    aux = argv[1].split('.')
    if aux[-1] != 'cm':
      raise IOError("Not a .cm file!")
    data = open(argv[1])

    source_file = data.read()

    # Printa a definicao da maquina.
    print(mealy)

    # Entrada lida do arquivo.
    print("Input:")
    print(source_file)

    # Mostra a saida.
    print("Output:")
    print(mealy.get_output_from_string(source_file.strip()))

