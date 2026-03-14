pkg load image;

entrada = imread("imagem.jpg");
figure(1);
imshow(entrada);
saida = zeros(679,800,"uint8");
tamanho = 679*800;
somaTotal = 0;
prrk = zeros(1,256);
sk = zeros(1,256);

[counts, x] = imhist(entrada);

for i = 1:256
  prrk(i) = counts(i)/tamanho;
endfor;

for j = 1:256
  somaTotal += prrk(j)*255;
  sk(j) = round(somaTotal);
endfor;

for k = 1:679
  for l = 1:800
    saida(k,l) = sk(entrada(k,l)+1);
  endfor;
endfor;

figure(2);
imshow(saida);

figure(3);
plot(sk, x, 'b');
axis([0 255 0 255]);

imwrite(saida, "saida.jpg");
