from automata.fa.Moore import Moore
from sys import argv

moore = Moore(['q0', 'q1', 'q2', 'q3', 'q4', 'q5'],
              ['0', '1'],
              ['0', '1'],
              {
                'q0': {'0': 'q0', '1': 'q1'},
                'q1': {'0': 'q0', '1': 'q2'},
                'q2': {'0': 'q3', '1': 'q2'},
                'q3': {'0': 'q0', '1': 'q4'},
                'q4': {'0': 'q0', '1': 'q5'},
                'q5': {'0': 'q3', '1': 'q2'},
              },
              'q0',
              {
                'q0': '0',
                'q1': '0',
                'q2': '0',
                'q3': '0',
                'q4': '0',
                'q5': '1',
              }
              )

              
print(moore)
print(moore.get_output_from_string('111011011'))

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
    print(moore)

    # Entrada lida do arquivo.
    print("Input:")
    print(source_file)

    # Mostra a saida.
    print("Output:")
    print(moore.get_output_from_string(source_file.strip()))

