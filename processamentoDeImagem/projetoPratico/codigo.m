pkg load image;
clc
clear all
close all
#carregando imagem inicial a ser tratada;
entrada = im2double(imread("Imagem.jpg"));
figure(1); imshow(entrada); title('Imagem de entrada');


#calculando M, N, P e Q1
[M,N, canais] = size(entrada);

P = M*2;
Q = N*2;

copia = entrada;

#aplicando zero padding
imagemPadded = padarray(copia, [max(0, P-M), max(0, Q-N)], 0, 'post');
figure(2); imshow(imagemPadded);  title('Imagem com zero padding aplicado');

#aplicando transformada
transformada = fftshift(fft2(imagemPadded));

#calculando espectro, espectro normalizado e salvando para fazer o filtro seletivo
espectro = log(1 + abs(transformada));
espectroNormalizado = (espectro - min(espectro(:))) / (max(espectro(:)) - min(espectro(:)));
figure(3); imshow(espectroNormalizado,[]);  title('Espectro de Fourier da imagem');
imwrite(espectroNormalizado, "espectro.jpg");

#com o espectro salvo, fizemos um filtro seletivo em um editor de imagem
filtro = im2double(imread("espectroFiltrado.jpg"));
figure(4); imshow(filtro); title('Filtro obtido através do espectro');

#aplicando filtro à transformada
transformadaFiltrada = transformada .* filtro;

#voltando transformada para o dominio espacial e retirando o lixo complexo com "real"
imagemFiltrada = real(ifft2(ifftshift(transformadaFiltrada)));

#voltando imagem para tamanho original e a normalizando
imagemFinalTransformada = imcrop(imagemFiltrada, [1,1,N-1,M-1]);

imagemFinalTransformada = (imagemFinalTransformada - min(imagemFinalTransformada (:))) / (max(imagemFinalTransformada (:)) - min(imagemFinalTransformada (:)));

figure(5); imshow(imagemFinalTransformada); title("Imagem com ruído periódico retirado");

#carregando os canais rgb
R = imagemFinalTransformada(:,:,1);
G = imagemFinalTransformada(:,:,2);
B = imagemFinalTransformada(:,:,3);

#fazendo o ajuste de contraste linear
Rr = imadjust(R, [0.1;0.95],[0;1]);
Gr = imadjust(G, [0.1;0.95],[0;1]);
Br = imadjust(B, [0.1;0.95],[0;1]);

#remontando os canais
imagemFinal = cat(3,Rr,Gr,Br);

#exibindo imagem final
figure(6); imshow(imagemFinal,[]); title("Imagem Final");
imwrite(imagemFinal, "imagemFinal.jpg");
