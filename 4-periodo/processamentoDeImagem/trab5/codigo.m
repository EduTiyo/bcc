pkg load image;

entrada = im2double(imread("Imagem.jpg"));
figure(1);
imshow(entrada);

[M,N,canais] = size(entrada); #tamanho da imagem

#tamanhos P e Q para zero padding
P = M*2;
Q = N*2;

#fazendo o zero padding
paddingHorizontal = max(0, Q-N);
paddingVertical = max(0, P-M);

imagemPadded = padarray(entrada, [paddingVertical, paddingHorizontal], 0, 'post'); #imagem no canto superior esquerdo
figure(1);
imshow(imagemPadded);


#centralizando para a transformada
[x,y] = meshgrid(1:Q,1:P);

mask = (-1).^(x+y);

imagemCentralizada = imagemPadded .* mask;
figure(2);
imshow(imagemCentralizada);

#aplicando transformada
fft_img = fft2(imagemCentralizada);

#mostrando espectro
espectro = log(1 + abs((fft_img) .* mask));
figure(3);
imshow(espectro, []);

espectro_normalizado = (espectro - min(espectro(:))) / (max(espectro(:)) - min(espectro(:)));
imwrite(espectro_normalizado, "espectro.jpg");

#fiz um filtro seletivo a partir do espectro usando um editor de foto

filtro = im2double(imread("espectroFiltrado.jpg"));

#aplicando filtro na transformada
transformadaFiltrada = fft_img .* filtro;

#voltando transformada do dominio da frequencia para o dominio espacial
imagemFiltrada = real(ifft2(transformadaFiltrada)) .* mask;
figure(4);
imshow(imagemFiltrada, []);

#imagem de tamanho original


imagemFinalTransformada = imcrop(imagemFiltrada, [1,1,N-1,M-1]);

figure(5);
imshow(imagemFinalTransformada);

R = imagemFinalTransformada(:,:,1);
G = imagemFinalTransformada(:,:,2);
B = imagemFinalTransformada(:,:,3);

#reajuste por contraste linear
Rr = imadjust(R);
Gr = imadjust(G);
Br = imadjust(B);

imagemContrastada = cat(3,Rr,Gr,Br);
figure(6); imshow(imagemContrastada, []);
imwrite(imagemContrastada, "imagemFinal.jpg");

