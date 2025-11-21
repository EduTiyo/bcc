import automata
def AFD(M, cadeia):
  (Q, Sigma, delta, q0, F) = M
  qA = q0
  for x in cadeia:
    if (qA, x) not in delta:
      return False
    qA = delta[(qA, x)]
  return qA in F


# exercicio 1
Q = ['q0', 'q1', 'q2', 'q3', 'q4']
Sigma = ['a', 'b']
delta = {('q0', 'a'): 'q4', ('q0', 'b'): 'q1',
 ('q1', 'a'): 'q1', ('q1', 'b'): 'q2', 
 ('q2','a'): 'q3', ('q2', 'b'): 'q4', 
 ('q3','b'): 'q4', ('q3', 'a'): 'q4', 
 ('q4', 'a'): 'q4', ('q4', 'b'): 'q4'}

F = ['q3']

print(AFD((Q, Sigma, delta, 'q0', F), 'aba'))
print(AFD((Q, Sigma, delta, 'q0', F), 'baaaaaaba'))
print(AFD((Q, Sigma, delta, 'q0', F), 'bba'))
print(AFD((Q, Sigma, delta, 'q0', F), 'babab'))

# exercicio 2
# Q = ['q0', 'q1', 'q2']
# Sigma = ['a', 'b']
# delta = {('q0', 'a'): 'q1', ('q0', 'b'): 'q1', 
#          ('q1', 'a'): 'q2', ('q1', 'b'): 'q2',
#          ('q2', 'a'): 'q0', ('q2', 'b'): 'q0'}
# F = ['q0']

# print(AFD((Q, Sigma, delta, 'q0', F), 'a'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'b'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'aab'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'ababba'))

# exercicio 3
# Q = ['q0', 'q1']
# Sigma = ['a', 'b']
# delta = {('q0', 'a'): 'q1', ('q0', 'b'): 'q1', 
#          ('q1', 'a'): 'q0', ('q1', 'b'): 'q0'}
# F = ['q0']

# print(AFD((Q, Sigma, delta, 'q0', F), 'a'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'b'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'ba'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'aab'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'ababba'))

# exercicio 4
# Q = ['q0', 'q1', 'q2', 'q3', 'q4', 'q5']
# Sigma = ['a', 'b']
# delta = {('q0', 'a'): 'q1', 
#          ('q1', 'a'): 'q2', ('q1', 'b'): 'q3', 
#          ('q2', 'a'): 'q1', ('q2', 'b'): 'q4', 
#          ('q3', 'b'): 'q4', 
#          ('q4', 'a'): 'q5', ('q4', 'b'): 'q3', 
#          ('q5', 'a'): 'q5', ('q5', 'b'): 'q5'}
# F = ['q3', 'q2', 'q0']

# print(AFD((Q, Sigma, delta, 'q0', F), 'a'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'ba'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'aabb'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'aabbbb'))

# exercicio 5
# Q = ['q0', 'q1', 'T']
# Sigma = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
# delta = {('q0', '0'): 'q1', ('q0', '2'): 'q1', ('q0', '4'): 'q1', ('q0', '6'): 'q1', ('q0', '8'): 'q1',
#          ('q0', '1'): 'T', ('q0', '3'): 'T', ('q0', '5'): 'T', ('q0', '7'): 'T', ('q0', '9'): 'T', 
#          ('q1', '0'): 'q1', ('q1', '2'): 'q1', ('q1', '4'): 'q1', ('q1', '6'): 'q1', ('q1', '8'): 'q1',
#          ('q1', '1'): 'T', ('q1', '3'): 'T', ('q1', '5'): 'T', ('q1', '7'): 'T', ('q1', '9'): 'T', 
#          ('T', '0'): 'q1', ('T', '2'): 'q1', ('T', '4'): 'q1', ('T', '6'): 'q1', ('T', '8'): 'q1',
#          ('T', '1'): 'T', ('T', '3'): 'T', ('T', '5'): 'T', ('T', '7'): 'T', ('T', '9'): 'T',}
# F = ['q1']

# print(AFD((Q, Sigma, delta, 'q1', F), '19'))
# print(AFD((Q, Sigma, delta, 'q0', F), '512'))
# print(AFD((Q, Sigma, delta, 'q0', F), '16'))
# print(AFD((Q, Sigma, delta, 'q0', F), '901'))

# exercicio 6
# Q = ['q0', 'q1', 'T']
# Sigma = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
# delta = {
#   ('q0', '0'): 'q1', ('q0', '5'): 'q1',
#   ('q0', '1'): 'T', ('q0', '2'): 'T', ('q0', '3'): 'T', ('q0', '4'): 'T', ('q0', '6'): 'T', ('q0', '7'): 'T', ('q0', '8'): 'T', ('q0', '9'): 'T',
#   ('q1', '0'): 'q1', ('q1', '5'): 'q1',
#   ('q1', '1'): 'T', ('q1', '2'): 'T', ('q1', '3'): 'T', ('q1', '4'): 'T', ('q1', '6'): 'T', ('q1', '7'): 'T', ('q1', '8'): 'T', ('q1', '9'): 'T',
#   ('T', '0'): 'q1', ('T', '5'): 'q1',
#   ('T', '1'): 'T', ('T', '2'): 'T', ('T', '3'): 'T', ('T', '4'): 'T', ('T', '6'): 'T', ('T', '7'): 'T', ('T', '8'): 'T', ('T', '9'): 'T',
# }
# F = ['q1']

# print(AFD((Q, Sigma, delta, 'q1', F), '19'))
# print(AFD((Q, Sigma, delta, 'q0', F), '512'))
# print(AFD((Q, Sigma, delta, 'q0', F), '16'))
# print(AFD((Q, Sigma, delta, 'q0', F), '900'))
# print(AFD((Q, Sigma, delta, 'q0', F), '15'))

# exercicio relatório
# Q = ['q0', 'q1', 'q2', 'q3', 'q4', 'q5']
# Sigma = ['a', 'b']
# delta = {
#   #q0
#   ('q0', 'b'): 'q1',
#   ('q0', 'a'): 'q5',

#   #q1
#   ('q1', 'a'): 'q4',
#   ('q1', 'b'): 'q2',

#   #q2
#   ('q2', 'a'): 'q3',
#   ('q2', 'b'): 'q0',

#   #q3
#   ('q3', 'a'): 'q2',
#   ('q3', 'b'): 'q5',

#   #q4
#   ('q4', 'a'): 'q1',
#   ('q4', 'b'): 'q3',

#   #q5
#   ('q5', 'a'): 'q0',
#   ('q5', 'b'): 'q4',

# }
# F = ['q5']

# print(AFD((Q, Sigma, delta, 'q1', F), 'aba'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'a'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'bbb'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'abbb'))
# print(AFD((Q, Sigma, delta, 'q0', F), 'bababa'))