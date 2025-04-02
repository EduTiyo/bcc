![code-snapshot4](https://github.com/EduTiyo/bcc/assets/128728277/b7889816-d103-4d9b-8158-be5e64c8e8f5)
##
Na imagem, temos a classe Professor, que apenas ensina. É imperativo que os objetos instanciados profGeo e profMat não ensinam a mesma matéria, portanto, o método ensinar() nao funcionaria, pois nao ensinam da mesma forma, ferindo, desse modo, o principio de substituicao de Liskov.
##
Para tratar, cria-se uma classe filha, a qual possui seu proprio metodo ensinar().
##
![code-snapshot4](https://github.com/EduTiyo/bcc/assets/128728277/7fae8889-9cdb-419c-9735-6ae5f886a6f0)
