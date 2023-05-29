# LogBook Relativo à Realização do Estudo da Radiação Gamma

A experiência que em seguida se descreve foi realizada no dia 29 de maio de 2023, com início às 8:15 da manhã e fim às 11:30. Nós somos o grupo 1D que é formado por

1. **Estudo de espectros de fontes conhecidas e calibração**:
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
        |  Centróide Pico Inicial   |   64.10 ± 0.26 Chn    |        -         |  32.96 Chn    |   9877 ± 99 Chn | 2909 ± 296   |
        |  Centróide Pico Gamma 1 |    760.24 ± 0.32 Chn   |    -   |   32.42 Chn |   2592 ± 51 Chn  |   1805 ± 112 Chn |
        |  Centróide Pico Gamma 2 |    861.42 ± 0.36 Chn   |  - |   36.82 Chn |   2228 ± 47 Chn  | 1856 ± 84 Chn |

   - Guardamos os dados obtidos para o espetro do cobalto na disquete, para posteriormente podermos analisá-los;
   - Note-se que tanto nesta aquisição de dados, como em todas as que se realizaram nesta experiência, calcularam-se as incertezas relativamente ao centróide com a fórmula sigma/sqrt(N) onde sigma é variância e é dada por FWHM/2.355 e N é igual ao ROI INT;
   - Em seguida retiramos a fonte de cobalto e colocamos a fonte de césio;
   - Voltamos a realizar uma aquisição de 2 minutos e, obtivemos os seguintes dados relativos aos picos de emissão do césio que pretendiamos estudar, nomeadamente o pico de raio X, o backscattering, o joelho de Compton e o pico de emissão Gamma:

        | Dados relativos ao espetro de emissão do Césio | Valor | Valor Calibrado | FWHM | ROI INT | ROI NET |
        |:----------------------------------------------------------------:|:-----:|:---------------:|:----:|:-------:|:-------:|
        |  Centróide BackScattering     |  136.82 ± 0.10 Chn    |      -        |  16.57 Chn | 26558 ± 163 Chn  | 4602 ± 384 Chn  |
        |   Centróide Joelho de Compton |   294 Chn    |        -         |   -   |     -    |     -    |
        |  Centróide Raios X            |   28.8 ± 0.01 Chn    |        -         |  3.47 Chn    |   42445 ± 206 Chn |   31578 ± 280   |
        |  Centróide Pico Gamma         |    436.07 ± 0.04 Chn   |       -      |   26.89 Chn |   84454 ± 291 Chn  |   82318 ± 341 Chn |

   - Em seguida, voltamos a calibrar o sistema com os valores obtidos para o pico
   - Fizemos a calibração através de uma regressão linear entre os channels do centróide e as energias tabeladas do pico raio-x e os raios gamma do cobalto e do césio, recorrendo a código e utilizando quatro pontos. Com a calibração, obtivémos valores para a energia dos picos obtidos anteriormente e comparamos com os valores tabelados. Apenas realizamos a calibração após ter os valores em Chn para os picos gamma do cobalto e os picos gamma e raio X do césio uma vez que a regressão linear fica mais precisa com uma maior quantidade de pontos (reduzimos os erros aleatórios). A energia calibrada é dada em unidades de KeV. A reta de ajuste obtida do tipo E(Chn) (energia em função de channels) e é dada por:
  
       $E(Chn) =  1.563*Chn - 15.732$
   - Recoorendo a esta regressão linear, preenchemos as tabelas de dados deste logbook com a energia correspondente a cada centróide medido;
2. **Identificação da fonte desconhecida**:
   - Começamos por sortear online a fonte desconhecida, tendo-nos sido atribuída a fonte vermelha 2;
   - Pedimos a fonte ao docente e colocámo-la em frente ao detetor de cintilação;
   - Iniciamos a aquisição de dados no MCA que durou 2 minutos e 30 segundos. Após esta aquisição, obtivemos os seguintes dados relativos aos picos de emissão da radiação da fonte desconhecida:

        | Dados relativos ao espetro de emissão da Fonte Vermelha 2 | Valor | Valor Calibrado | FWHM | ROI INT | ROI NET |
        |:----------------------------------------------------------------:|:-----:|:---------------:|:----:|:-------:|:-------:|
        | Centróide Pico 1 |  34.63 ± 0.01 Chn |  -  | 4.03 Chn  | 26082 ± 161 Chn | 22540 ± 188 Chn |
        | Centróide Pico 2 |  68.27 ± 0.09 Chn |  -  | 8.51 Chn  | 7391 ± 86 Chn | 1736 ± 179 Chn |
        | Centróide Pico 3 |  90.30 ± 0.03 Chn |  -  | 6.35 Chn  | 12404 ± 111 Chn | 8398 ± 154 Chn |
        | Centróide Pico 4 | 168.43 ± 0.14 Chn |  -  | 13.0 Chn  | 4167 ± 65 Chn | 1628 ± 127 Chn |
        | Centróide Pico 5 | 233.11 ± 0.11 Chn |  -  | 17.48 Chn | 6429 ± 80 Chn | 4490 ± 141 Chn |
        | Centróide Pico 6 | 509.49 ± 0.14 Chn |  -  | 8.06 Chn  | 1742 ± 42 Chn | 629 ± 108 Chn |
        | Centróide Pico 7 | 625.37 ± 0.54 Chn |  -  | 27.84 Chn | 1147 ± 34 Chn | 472 ± 85 Chn |
        | Centróide Pico 8 | 711.47 ± 0.35 Chn |  -  | 18.92 Chn | 1322 ± 36 Chn | 523 ± 90 Chn |
        | Centróide Pico 9 | 910.53 ± 0.30 Chn |  -  | 15.68 Chn | 760 ± 20 Chn | 485 ± 65 Chn |
        

   - 
3. **Identificação de fontes de radioactividade ambiente**
   - Retiramos as fontes radioativas das proximidades do detetor e iniciamos uma aquisição de dados durante 20 minutos com o objetivo de estudar a radiação proveniente do ambiente (erros sistemáticos);
   - Após a aquisição, verificámos que existem 2 picos/estruturas mais relevantes. O primeiro encontra-se nas baixas energias e representa a radiação de fundo, associada a sucessivas perdas de energia. Para o segundo (mais energético) confirmámos, pelo cálculo da energia através da calibração, que corresponde ao pico de emissão gamma do potássio-40. Os dados obtidos foram os seguintes

        | Dados relativos ao espetro de emissão da Radiação de Fundo | Valor | Valor Calibrado | FWHM | ROI INT | ROI NET |
        |:----------------------------------------------------------------:|:-----:|:---------------:|:----:|:-------:|:-------:|
        | Centróide Pico de baixas energias |   69.15 ±  Chn |  -  | 60.60 Chn  | 96736 ± 311 Chn | 54923 ± 1036 Chn |
        | Centróide Pico de altas energias  |   943.57 ±  Chn |  -  | 26.63 Chn  | 1397 ± 37 Chn | 923 ± 87 Chn |

   - 
4. 
5. 





        | Dados relativos ao espetro de emissão da Fonte Vermelha 2 | Valor | Valor Calibrado | FWHM | ROI INT | ROI NET |
        |:----------------------------------------------------------------:|:-----:|:---------------:|:----:|:-------:|:-------:|
        | Centróide Pico 1 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 2 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 3 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 4 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 5 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 6 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 7 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 8 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |
        | Centróide Pico 9 |   +- Chn |  -  |  Chn |  +-  Chn |  +-  Chn |