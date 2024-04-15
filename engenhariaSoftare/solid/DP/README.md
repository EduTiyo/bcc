![code-snapshot3](https://github.com/EduTiyo/bcc/assets/128728277/61c9163d-f906-492c-a45c-f392af38b979)
##
Na implementação acima, há a violação do princípio de Demeter, onde o objeto carro acessa o método start() indiretamente, retornando uma instancia da classe Motor, para entao utilizar o start() do Motor. O correto seria a classe Carro ter um método que acessasse os metodos de Motor, entao o objeto precisa somente utilizar um método na main.
##
![code-snapshot3](https://github.com/EduTiyo/bcc/assets/128728277/62e73c25-7f82-482c-a767-0070ee4082ab)
##
Acima está um exemplo de um implementacao que nao viola os principios de Demeter
