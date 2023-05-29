# LogBook Relativo à Realização do Estudo da Radiação Gamma

A experiência que em seguida se descreve foi realizada no dia 29 de maio de 2023, com início às 8:15 da manhã e fim às 11:30. Nós somos o grupo 1D que é formado por

1. Estudo de espectros de fontes conhecidas e calibração:
   - Começámos por pedir ao docente a fonte de césio e colocámo-la em frente ao cintilador, na primeira raxa;
   - Em seguida ligámos o computador, iniciámos o MCA, ligámos o cintilador ao INPUT do amplificador (que já se encontrava ajustado) e o OUTPUT unipolar do amplificador ao computador;
   - Ligamos a Fonte de alta tensão, que também já se encontrava ajustada;
   - Selecionámos o tempo de aquisição para 2 minutos e iniciàmos a aquisição do espetro de emissão da radiação fonte de césio;
   - Em seguida, registámos os dados relativos aos picos de emissão do césio que pretendiamos estudar, nomeadamente o pico de raio X, o backscattering, o joelho de Compton e o pico de emissão Gamma, obtendo os seguintes dados :

        | Dados relativos ao espetro de emissão do Césio | Valor | Valor Calibrado | FWHM | ROI INT | ROI NET |
        |:----------------------------------------------------------------:|:-----:|:---------------:|:----:|:-------:|:-------:|
        |  Centróide BackScattering     |  162.13 +- Chn    |      -        |  20.51 Chn | 26210 +- 162 Chn  | 4561 +- 459 Chn  |
        |   Centróide Joelho de Compton   |   355 Chn    |        -         |   -   |     -    |     -    |
        |  Centróide Raios X   |   33.25 +- Chn    |        -         |  3.92 Chn    |   33874 +- 184 Chn |   25157 +- 259   |
        |  Centróide Pico Gamma   |    516.15 +- Chn   |       -      |   31.31 Chn |   67306 +- 259 Chn  |   63023 +- 346 Chn |
 
   - Fizemos a calibração através de uma regressão linear entre os channels do centróide e as energias tabeladas do pico raio-x e raio gamma, recorrendo a código. Com a calibração, obtivémos valores para a energia do backscattering e do joelho de compton e comparámos com os valores tabelados;
   - Em seguida, retirámos a fonte de césio e colocámos a fonte de cobalto em frente ao detetor de cintilação;
   - Limpámos o MCA e iniciámos uma nova aquisição de 2 minutos para a nova fonte. 
   - Percebemos que nos dados obtidos não conseguiamos visualizar o segundo pico da radiação gamma do cobalto, e para que este pico aparecesse no espetro, foi necessário reduzir o fine gain do amplificador. Para saber quanto tinhamos de reduzir o fine gain, retirámos as fontes do detetor e inciámos recursivamente aquisições de dados no MCA para detetas a radição ambiente de fundo, cada vez reduzindo o valor do fine gain, até que seja possível visualizar o pico de fundo associado à emissão do potássio ambiente ( de valor tabelado 1460.830 eV ). Fizemos isto porque sabiamos que o pico de radiação gamma do potássio é mais energético que o segundo pico de radiação gamma do cobalto. Tivemos que realizar este processo três vezes até detetar o pico do potássio;
   - Concluimos que o ajuste ideal do amplificador seria com o coarse gain em 10x e o fine gain em 0.8x;
   - Em seguida, voltámos a colocar a fonte de cobalto e iniciamos a aquisição do seu espetro de energia durante 2 minutos;
   - Registámos os dados relativos aos picos de emissão do cobalto que pretendiamos estudar, nomeadamente o pico de raio X e os dois picos de emissão Gamma, obtendo os seguintes dados:

        | Dados relativos ao espetro de emissão do Cobalto | Valor | Valor Calibrado | FWHM | ROI INT | ROI NET |
        |:----------------------------------------------------------------:|:-----:|:---------------:|:----:|:-------:|:-------:|
        |  Centróide Pico Inicial   |   64.10 +- Chn    |        -         |  32.96 Chn    |   9877 +- 99 Chn | 2909 +- 296   |
        |  Centróide Pico Gamma 1 |    760.24 +- Chn   |    -   |   32.42 Chn |   2592 +- 51 Chn  |   1805 +- 112 Chn |
        |  Centróide Pico Gamma 2 |    861.42 +- Chn   |  - |   36.82 Chn |   2228 +- 47 Chn  | 1856 +- 84 Chn |

   - Guardamos os dados obtidos para o espetro do cobalto na disquete, para posteriormente podermos analisá-los;
   - Em seguida retiramos a fonte de cobalto e colocamos a fonte de césio;
   - Voltamos a realizar uma aquisição de 2 minutos e, obtivemos os seguintes dados relativos aos picos de emissão do césio que pretendiamos estudar, nomeadamente o pico de raio X, o backscattering, o joelho de Compton e o pico de emissão Gamma:

        | Dados relativos ao espetro de emissão do Césio | Valor | Valor Calibrado | FWHM | ROI INT | ROI NET |
        |:----------------------------------------------------------------:|:-----:|:---------------:|:----:|:-------:|:-------:|
        |  Centróide BackScattering     |  136.82 +- Chn    |      -        |  16.57 Chn | 26558 +- 163 Chn  | 4602 +- 384 Chn  |
        |   Centróide Joelho de Compton   |   294 Chn    |        -         |   -   |     -    |     -    |
        |  Centróide Raios X   |   28.8 +- Chn    |        -         |  3.47 Chn    |   42445 +- 206 Chn |   31578 +- 280   |
        |  Centróide Pico Gamma   |    436.07 +- Chn   |       -      |   26.89 Chn |   84454 +- 291 Chn  |   82318 +- 341 Chn |

   - Em seguida, voltamos a calibrar o sistema com os valores obtidos para o pico
   - Fizemos a calibração através de uma regressão linear entre os channels do centróide e as energias tabeladas do pico raio-x e os raios gamma do cobalto e do césio, recorrendo a código e utilizando quatro pontos. Com a calibração, obtivémos valores para a energia dos picos obtidos anteriormente e comparamos com os valores tabelados. Apenas realizamos a calibração após ter os valores em Chn para os picos gamma do cobalto e os picos gamma e raio X do césio uma vez que a regressão linear fica mais precisa com uma maior quantidade de pontos (reduzimos os erros aleatórios). A reta de ajuste obtida do tipo E(Chn) (energia em função de channels) e é dada por:
        $E(Chn) = $
   - 

2. 
3. 