pkg load image;

entrada = imread("very_low_contrast_gray_image.png");
figure(1);
imshow(entrada);
saida = zeros(576,1024,"uint8");
tamanho = 576*1024;
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

for k = 1:576
  for l = 1:1024
    saida(k,l) = sk(entrada(k,l)+1);
  endfor;
endfor;

figure(2);
imshow(saida);

figure(3);
plot(sk, x, 'b');
axis([0 255 0 255]);

imwrite(saida, "saida.jpg");
