pkg load image;

entrada = im2double(imread("pratica4.jpg"));
#imshow(entrada);
filtroMedia = ones(9,9,"double")/81;


saida1 = zeros(306,306, "double");

saida1 = filter2(filtroMedia,entrada,"full");
figure(1);
imshow(saida1); #a imagem ficou borrada e com a borda preta, tambem borrada.

entradaPadding4 = padarray(entrada, [4,4], "replicate");

saida2 = filter2(filtroMedia, entradaPadding4, "valid");
figure(2);
imshow(saida2);

entradaPaddingSobel = padarray(entrada, [1,1], "replicate");

filtroSobelX = [-1 0 1; -2 0 2; -1 0 1];
filtroSobelY = [-1 -2 -1; 0 0 0; 1 2 1];

gx = filter2(filtroSobelX, entradaPaddingSobel, "valid");
gy = filter2(filtroSobelY, entradaPaddingSobel, "valid");

M = abs(gx) + abs(gy);

figure(3);
imshow(M,[]);
