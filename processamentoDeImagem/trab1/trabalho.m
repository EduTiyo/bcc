imRuim = im2double(imread("tungsten_filament_shaded.tif"));
shade = im2double(imread("tungsten_sensor_shading.tif"));
imBoa = imRuim ./ shade;

figure(1);
imshow(imRuim);
figure(2);
imshow(imBoa);

imwrite(imBoa, "imagemDeSaida.tif");
