% Faixa de 16kHz: Super-Agudos (sons de pratos de baterias com mais suavidade e clareza, alguns ouvidos humanos não alcançam essa frequência).
% Faixa de 8 kHz: Agudos (sons de pratos de baterias com mais estridência).
% Faixa de 4 kHz: Médios-agudos (voz humana com tom mais agudo).
% Faixa de 2 kHz: Médios-altos (vozes humanas soam com estridência).
% Faixa de 1 kHz: Médios (a voz humana natural se encontra nessa faixa).
% Faixa de 500Hz: Médios-baixos (não há batidas graves da música nessa faixa e a voz humana é com tom grave nessa faixa).
% Faixa de 250Hz: Médio-graves baixos (não há som de vozes humanas nessa faixa).
% Faixa de 125Hz: Graves Altos (graves com mais ataque nessa faixa).
% Faixa de 64Hz: Graves (graves mais retumbantes e encorpados nessa faixa).
% Faixa de 32Hz: Sub-Graves (graves extensos, prolongados e macios nessa faixa)

options = bodeoptions;
options.FreqUnits = 'Hz'; % or 'rad/second', 'rpm', etc.

band1 = tf([(1*2*pi) 0],[1 (1*2*pi)  (2*pi*32)^2]);
band2 = tf([(2*2*pi) 0],[1 (2*2*pi)  (2*pi*64)^2]);
band3 = tf([(2*2*pi) 0],[1 (2*2*pi)  (2*pi*125)^2]);
band4 = tf([(4*2*pi) 0],[1 (4*2*pi)  (2*pi*250)^2]);
band5 = tf([(16*2*pi) 0],[1 (16*2*pi)  (2*pi*500)^2]);
band6 = tf([(16*2*pi) 0],[1 (16*2*pi)  (2*pi*1000)^2]);
band7 = tf([(32*2*pi) 0],[1 (32*2*pi)  (2*pi*2000)^2]);
band8 = tf([(32*2*pi) 0],[1 (32*2*pi)  (2*pi*4000)^2]);
band9 = tf([(64*2*pi) 0],[1 (64*2*pi)  (2*pi*8000)^2]);
band10 = tf([(128*2*pi) 0],[1 (128*2*pi)  (2*pi*16000)^2]);


% wo = 2*pi*60;  % notch frequency
% wb = 2*2*pi;    % width frequency
% a = 1;
% notch = tf(a*[1 0 wo^2],[1 wb wo^2])
% %nfd = c2d(nf,1/36000,'tustin');

bode(band1,band2,band3,band4,band5,band6,band7,band8,band9,band10,options);

temp = c2d(band1,1/88200,'tustin');
disp(sprintf('band1.a1 = %f;\nband1.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band1.b0 = %fE-4;\nband1.b1 = %fE-4;\nband1.b2 = %fE-4;\n',temp.num{1}(1)*1e4,temp.num{1}(2)*1e4,temp.num{1}(3)*1e4));

temp = c2d(band2,1/88200,'tustin');
disp(sprintf('band2.a1 = %f;\nband2.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band2.b0 = %fE-4;\nband2.b1 = %fE-4;\nband2.b2 = %fE-4;\n',temp.num{1}(1)*1e4,temp.num{1}(2)*1e4,temp.num{1}(3)*1e4));

temp = c2d(band3,1/88200,'tustin');
disp(sprintf('band3.a1 = %f;\nband3.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band3.b0 = %fE-4;\nband3.b1 = %fE-4;\nband3.b2 = %fE-4;\n',temp.num{1}(1)*1e4,temp.num{1}(2)*1e4,temp.num{1}(3)*1e4));

temp = c2d(band4,1/88200,'tustin');
disp(sprintf('band4.a1 = %f;\nband4.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band4.b0 = %fE-4;\nband4.b1 = %fE-4;\nband4.b2 = %fE-4;\n',temp.num{1}(1)*1e4,temp.num{1}(2)*1e4,temp.num{1}(3)*1e4));

temp = c2d(band5,1/88200,'tustin');
disp(sprintf('band5.a1 = %f;\nband5.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band5.b0 = %fE-3;\nband5.b1 = %fE-3;\nband5.b2 = %fE-3;\n',temp.num{1}(1)*1e3,temp.num{1}(2)*1e3,temp.num{1}(3)*1e3));

temp = c2d(band6,1/88200,'tustin');
disp(sprintf('band6.a1 = %f;\nband6.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band6.b0 = %fE-3;\nband6.b1 = %fE-3;\nband6.b2 = %fE-3;\n',temp.num{1}(1)*1e3,temp.num{1}(2)*1e3,temp.num{1}(3)*1e3));

temp = c2d(band7,1/88200,'tustin');
disp(sprintf('band7.a1 = %f;\nband7.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band7.b0 = %fE-3;\nband7.b1 = %fE-3;\nband7.b2 = %fE-3;\n',temp.num{1}(1)*1e3,temp.num{1}(2)*1e3,temp.num{1}(3)*1e3));

temp = c2d(band8,1/88200,'tustin');
disp(sprintf('band8.a1 = %f;\nband8.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band8.b0 = %fE-3;\nband8.b1 = %fE-3;\nband8.b2 = %fE-3;\n',temp.num{1}(1)*1e3,temp.num{1}(2)*1e3,temp.num{1}(3)*1e3));

temp = c2d(band9,1/88200,'tustin');
disp(sprintf('band9.a1 = %f;\nband9.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band9.b0 = %fE-2;\nband9.b1 = %fE-2;\nband9.b2 = %fE-2;\n',temp.num{1}(1)*1e2,temp.num{1}(2)*1e2,temp.num{1}(3)*1e2));

temp = c2d(band10,1/88200,'tustin');
disp(sprintf('band10.a1 = %f;\nband10.a2 = %f;',temp.den{1}(2),temp.den{1}(3)));
disp(sprintf('band10.b0 = %fE-2;\nband10.b1 = %fE-2;\nband10.b2 = %fE-2;\n',temp.num{1}(1)*1e2,temp.num{1}(2)*1e2,temp.num{1}(3)*1e2));

