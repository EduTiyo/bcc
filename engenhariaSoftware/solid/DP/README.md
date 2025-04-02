![3](https://github.com/EduTiyo/bcc/assets/128728277/3c9134ce-40d4-42d1-b047-2a7ac51e0103)
##
No código acima, vemos que a classe Carro tem o método getEngine, o qual devolve um atributo do tipo Motor. Por sua vez, o motor é iniciado pelo metoto Start de Motor. Na main, primeiro é preciso chamar o método getEngine e depois o start, para iniciar o carro, expondo assim o Motor. 
##
Para corrigir isso, basta trocar o método de Carro para um método que chama o método start de Motor, assim, não é necessário expor o Motor.
##
![4](https://github.com/EduTiyo/bcc/assets/128728277/a1f66ede-0891-4848-a406-a5fdfe19d15a)
