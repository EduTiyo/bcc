clc
clear all
close all
pkg load image;

#carrega imagem original
entrada = im2double(imread("Imagem.jpg"));
figure; imshow(entrada); title("Imagem original");

#transformando para hsi
HSV = rgb2hsv(entrada);

#calculando M, N, P e Q
[M,N,canais] = size(entrada);
P = M*2;
Q = N*2;

#separando H, S e V
Hr = HSV(:,:,1);
Sr = HSV(:,:,2);
Vr = HSV(:,:,3);
figure; imshow(Vr); title("Componente V");

#adicionar o zero padding
imagemPadded = padarray(Vr, [max(0,P-M), max(0,Q-N)], 0, 'post');
figure; imshow(imagemPadded); title("Imagem com zero padding aplicado");

#aplicando transformada
transformada = fftshift(fft2(imagemPadded));

#mostrando espectro
espectro = log(1 + abs(transformada));
figure; imshow(espectro, []); title("Espectro de Fourier da imagem");
espectroNormalizado = (espectro - min(espectro(:))) / (max(espectro(:)) - min(espectro(:)));
imwrite(espectroNormalizado, "espectro.jpg");

#filtro notch feito a partir do espectro. em um editor de foto
filtro = im2double(imread("filtro.jpg"));
figure; imshow(filtro); title("Filtro obtido");

#aplicando o filtro na transformada
transformadaFiltrada = transformada .* filtro;

#transformada inversa
vFiltrado = real(ifft2(ifftshift(transformadaFiltrada)));

#normalizando o V para melhor contraste
vContrastado = imadjust(vFiltrado, [0.1;0.95],[0;1]);

#voltando imagem ao tamanho original
imgFinal = imcrop(vFiltrado, [1,1,N-1,M-1]);

#remontando o hsi
imgRemontada = hsv2rgb(cat(3,Hr,Sr,imgFinal));
figure; imshow(imgRemontada); title("Imagem final");
imwrite(imgRemontada, "imagemFinal.jpg");




