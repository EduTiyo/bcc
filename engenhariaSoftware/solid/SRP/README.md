![code-snapshot1](https://github.com/EduTiyo/bcc/assets/128728277/cd1cbee2-5853-4fda-98e8-3156c9285297)
##
Nesse código, podemos ver que o princípio de responsabilidade única é quebrado, haja vista que o método cadastrarAlunoErrado() possui duas responsabilidades: atribuir os valores dos parâmetros na instância criada, e, logo depois, é printado, sendo esta, a segunda responsabilidade.

##

Para corrigir o problema, criei outra classe console, a qual possui o método imprimirAluno(), assim, deixando uma responsabilidade para cada método. É vantajoso pois outras classes podem usufruir do mesmo método.
Faz-se isso pois as interfaces devem ser pequenas, coesas e especificas para cada tipo de cliente

![code-snapshot1](https://github.com/EduTiyo/bcc/assets/128728277/59127022-4462-4d09-9eac-73f88e56703e)
