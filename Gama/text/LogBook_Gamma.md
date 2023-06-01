# LogBook Relativo à Realização do Estudo da Radiação Gamma

A experiência que em seguida se descreve foi realizada no dia 29 de maio de 2023, com início às 8:15 da manhã e fim às 11:30. O nosso grupo é o 1D e é formado pelo Estêvão Gomes (ist1102650), o Pedro Curvo (ist1102716), a Sofia Tété (ist1102633) e o Salvador Torpes (ist1102474). LogBook realizado por Salvador Torpes

1. **Estudo de espectros de fontes conhecidas e calibração**:
   - Começámos por pedir ao docente a fonte de césio e colocámo-la em frente ao cintilador, na primeira raxa;
   - Em seguida ligámos o computador, iniciámos o MCA, ligámos o cintilador ao INPUT do amplificador (que já se encontrava ajustado) e o OUTPUT unipolar do amplificador ao computador;
   - Ligamos a Fonte de alta tensão, que também já se encontrava ajustada;
   - Selecionámos o tempo de aquisição para 2 minutos e iniciàmos a aquisição do espetro de emissão da radiação fonte de césio;
   - Em seguida, registámos os dados relativos aos picos de emissão do césio que pretendiamos estudar, nomeadamente o pico de raio X, o backscattering, o joelho de Compton e o pico de emissão Gamma, obtendo os seguintes dados :
     
      ### Dados relativos ao espetro de emissão do Césio


        |  | Valor [Chn]| Valor Calibrado [keV] | FWHM [Chn] | ROI INT | ROI NET |
        |:--------:|:-----:|:----------:|:------:|:-----:|:-----:|
        |  Centróide BackScattering     |  162.13    |      -        |  20.51 | 26210 ± 162  | 4561 ± 459  |
        |   Centróide Joelho de Compton   |   355    |        -         |   -   |     -    |     -    |
        |  Centróide Raios X   |   33.25    |        -         |  3.92    |   33874 ± 184 |   25157 ± 259   |
        |  Centróide Pico Gamma   |    516.15   |       -      |   31.31 |   67306 ± 259 |   63023 ± 346 |


   - Fizemos a calibração através de uma regressão linear entre os channels do centróide e as energias tabeladas do pico raio-x e raio gamma, recorrendo a código. Com a calibração, obtivémos valores para a energia do backscattering e do joelho de compton e comparámos com os valores tabelados;
   - Em seguida, retirámos a fonte de césio e colocámos a fonte de cobalto em frente ao detetor de cintilação;
   - Limpámos o MCA e iniciámos uma nova aquisição de 2 minutos para a nova fonte. 
   - Percebemos que nos dados obtidos não conseguiamos visualizar o segundo pico da radiação gamma do cobalto, e para que este pico aparecesse no espetro, foi necessário reduzir o fine gain do amplificador. Para saber quanto tinhamos de reduzir o fine gain, retirámos as fontes do detetor e inciámos recursivamente aquisições de dados no MCA para detetas a radição ambiente de fundo, cada vez reduzindo o valor do fine gain, até que seja possível visualizar o pico de fundo associado à emissão do potássio ambiente ( de valor tabelado 1460.830 eV ). Fizemos isto porque sabiamos que o pico de radiação gamma do potássio é mais energético que o segundo pico de radiação gamma do cobalto. Tivemos que realizar este processo três vezes até detetar o pico do potássio;
   - Concluimos que o ajuste ideal do amplificador seria com o coarse gain em 10x e o fine gain em 0.8x;
   - Em seguida, voltámos a colocar a fonte de cobalto e iniciamos a aquisição do seu espetro de energia durante 2 minutos;
   - Registámos os dados relativos aos picos de emissão do cobalto que pretendiamos estudar, nomeadamente o pico de raio X e os dois picos de emissão Gamma, obtendo os seguintes dados:

      ### Dados relativos ao espetro de emissão do Cobalto

        |  | Valor [Chn]| Valor Calibrado [keV] | FWHM [Chn] | ROI INT | ROI NET |
        |:--------:|:-------:|:----------:|:------:|:-----:|:-----:|
        |  Centróide Pico Inicial   |   64.10 ± 0.26    |        84.46          |  32.96      |   9877 ± 99   | 2909 ± 296   |
        |  Centróide Pico Gamma 1 |    760.24 ± 0.32     |    1172.57      |   32.42   |   2592 ± 51    |   1805 ± 112   |
        |  Centróide Pico Gamma 2 |    861.42 ± 0.36     |  1330.72    |   36.82   |   2228 ± 47    | 1856 ± 84   |

     ![Cobalto](images/Cobalto.jpeg)
   - Verificámos a existência de 2 picos de alta energia, associados à radiação gama. Nas baixas energias existe também um pico associado a radiação de fundo e possível sobreposição de raios-x;
   - Guardamos os dados obtidos para o espetro do cobalto na disquete, para posteriormente podermos analisá-los;
   - Note-se que tanto nesta aquisição de dados, como em todas as que se realizaram nesta experiência, calcularam-se as incertezas relativamente ao centróide com a fórmula sigma/sqrt(N) onde sigma é variância e é dada por FWHM/2.355 e N é igual ao ROI INT;
   - Em seguida retiramos a fonte de cobalto e colocamos a fonte de césio;
   - Voltamos a realizar uma aquisição de 2 minutos e, obtivemos os seguintes dados relativos aos picos de emissão do césio que pretendiamos estudar, nomeadamente o pico de raio X, o backscattering, o joelho de Compton e o pico de emissão Gamma:

     ### Dados relativos ao espetro de emissão do Césio

        |  | Valor [Chn]| Valor Calibrado [keV] | FWHM [Chn] | ROI INT | ROI NET |
        |:--------:|:-------:|:----------:|:------:|:-----:|:-----:|
        |  Centróide BackScattering     |  136.82 ± 0.10      |   198.13      |  16.57   | 26558 ± 163    | 4602 ± 384    |
        |  Centróide Joelho de Compton  |   294               |   443.81      |   -   |     -    |     -    |
        |  Centróide Raios X            |   28.8 ± 0.01       |   29.28      |  3.47      |   42445 ± 206   |   31578 ± 280   |
        |  Centróide Pico Gamma         |   436.07 ± 0.04     |   665.87      |   26.89   |   84454 ± 291    |   82318 ± 341   |

     ![Césio](images/Cesio.jpeg)
   - Verificámos que nas energias mais baixas existe um pico alto e fino, ao qual correpondem raios-x. Posteriormente temos o patamar de Compton, no centro do qual existe um pequeno pico de backscattering. No fim do patamar confirmámos a existência de um joelho de Compton. Por fim, vimos um pico na zona de altas energias, correspondente à radiação gama. Caso o detetor fosse ideal, o pico seria estreito correspondendo apenas a uma energia. No entanto, existe uma dispersão relacionada com a resolução em energia do detetor, a qual torna os picos mais energéticos mais largos. Quanto mais energética for a radiação incidente, mais energéticos são os fotões que entram no cristal. Quanto mais energéticos são os fotões, maior é o número de choques no cristal do detetor, pelo que as flutuações no valor medido são maiores.
   - Guardamos os dados obtidos para o espetro do cobalto na disquete, para posteriormente podermos analisá-los;
   - Fizemos a calibração através de uma regressão linear entre os channels do centróide e as energias tabeladas do pico raio-x e os raios gamma do cobalto e do césio, recorrendo a código e utilizando quatro pontos. Com a calibração, obtivémos valores para a energia dos picos obtidos anteriormente e comparamos com os valores tabelados. Apenas realizamos a calibração após ter os valores em Chn para os picos gamma do cobalto e os picos gamma e raio X do césio uma vez que a regressão linear fica mais precisa com uma maior quantidade de pontos (reduzimos os erros aleatórios). A energia calibrada é dada em unidades de KeV. A reta de ajuste obtida do tipo E(Chn) (energia em função de channels) e é dada por:
  
       $E(Chn) =  1.563*Chn - 15.732$
   - Recoorendo a esta regressão linear, preenchemos as tabelas de dados deste logbook com a energia correspondente a cada centróide medido;
2. **Identificação da fonte desconhecida**:
   - Começamos por sortear online a fonte desconhecida, tendo-nos sido atribuída a fonte vermelha 2;
   - Pedimos a fonte ao docente e colocámo-la em frente ao detetor de cintilação;
   - Iniciamos a aquisição de dados no MCA que durou 2 minutos e 30 segundos. Após esta aquisição, obtivemos os seguintes dados relativos aos picos de emissão da radiação da fonte desconhecida:

     ### Dados relativos ao espetro de emissão da Fonte Vermelha 2

        |  | Valor [Chn]| Valor Calibrado [keV] | FWHM [Chn] | ROI INT | ROI NET |
        |:--------:|:-------:|:----------:|:------:|:-----:|:-----:|
        | Centróide Pico 1 |  34.63 ± 0.01   | 38.40      | 4.03    | 26082 ± 161   | 22540 ± 188   |
        | Centróide Pico 2 |  68.27 ± 0.09   | 91.00      | 8.51    | 7391 ± 86   | 1736 ± 179   |
        | Centróide Pico 3 |  90.30 ± 0.03   | 125.41      | 6.35    | 12404 ± 111   | 8398 ± 154   |
        | Centróide Pico 4 | 168.43 ± 0.14   | 247.53      | 13.0    | 4167 ± 65   | 1628 ± 127   |
        | Centróide Pico 5 | 233.11 ± 0.11   | 348.63      | 17.48   | 6429 ± 80   | 4490 ± 141   |
        | Centróide Pico 6 | 509.49 ± 0.14   | 780.63      | 8.06    | 1742 ± 42   | 629 ± 108   |
        | Centróide Pico 7 | 625.37 ± 0.54   | 961.76      | 27.84   | 1147 ± 34   | 472 ± 85   |
        | Centróide Pico 8 | 711.47 ± 0.35   | 1096.34      | 18.92   | 1322 ± 36   | 523 ± 90   |
        | Centróide Pico 9 | 910.53 ± 0.30   | 1407.48      | 15.68   | 760 ± 20   | 485 ± 65   |
        

     ![Fonte_Vermelha2](images/Desconhecida.jpeg)

   - Guardamos os dados obtidos para o espetro do cobalto na disquete, para posteriormente podermos analisá-los;
1. **Identificação de fontes de radioactividade ambiente**
   - Retiramos as fontes radioativas das proximidades do detetor e iniciamos uma aquisição de dados durante 20 minutos com o objetivo de estudar a radiação proveniente do ambiente (erros sistemáticos);
   - Após a aquisição, verificámos que existem 2 picos/estruturas mais relevantes. O primeiro encontra-se nas baixas energias e representa a radiação de fundo, associada a sucessivas perdas de energia. Para o segundo (mais energético) confirmámos, pelo cálculo da energia através da calibração, que corresponde ao pico de emissão gamma do potássio-40. Os dados obtidos foram os seguintes:

     ### Dados relativos ao espetro de emissão da Radiação de Fundo
        |  | Valor [Chn]| Valor Calibrado [keV] | FWHM [Chn] | ROI INT | ROI NET |
        |:--------:|:-------:|:----------:|:------:|:-----:|:-----:|
        | Centróide Pico de baixas energias |   69.15 ± 0.11   |  92.35      | 60.60    | 96736 ± 311   | 54923 ± 1036   |
        | Centróide Pico de altas energias  |   943.57 ± 0.37   |  1459.12      | 26.63    | 1397 ± 37   | 923 ± 87   |
        
     ![Fundo](images/Fundo.jpeg)
     
   - Verificámos que existem 2 picos mais relevantes. O primeiro encontra-se nas baixas energias e representa a radiação de fundo, associada a sucessivas perdas de energia. O segundo, mais energético, confirmámos que pelo cálculo da energia através da calibração que corresponde ao potássio-40.

2. **Atenuação da radiação gama na matéria**:
   - Para atenuação dos raios gamas usou-se duas placas de chumbo, uma de espessura 0.250 inches e 7200 mg/cm2 de espessura mássica e outra de 0.062 inches de espessura e 1200 mg/cm2 de espessura mássica. Para saber a espessura das placas é necessário o multiplicar valor escrito na caixa pela densidade do chumbo que é 11.34 g/cm3. As unidades de espessura mássica são úteis pois definem a atenuaçãocausada pela placa. Efetivamente, observa-se no osciloscópio que a atenuação é maior (observam-se menos picos de alta energia)quando se usa a placa de chumbo mais espessa.
   - Colocou-se a placa de chumbo mais espessa entre o detetor e a fonte radioativa (Cs 137).
   - Foram registado no MCA durante 150s o espetro de amissão da fonte com a placa de chumbo colocada.
   - Repetiu-se o procedimento para a placa de chumbo mais fina.
   - Para a placa de chumbo muito espesso, obtivemos os seguintes dados:
     
     ![Chumbo Muito Espesso](images/Chumbo_Espesso.jpeg)


     ### Dados relativos ao espetro de emissão do césio com a Placa de Chumbo muito espesso

        |  | Valor [Chn]| Valor Calibrado [keV] | FWHM [Chn] | ROI INT | ROI NET |
        |:--------:|:-------:|:----------:|:------:|:-----:|:-----:|
        | Centróide Pico 1 |  59.59 ± 0.06   |  77.41      | 5.83    | 9364 ± 97   | 1552 ± 223   |
        | Centróide Pico 2 |  136.56 ± 0.17   |  197.72      | 20.98    | 15112 ± 123   | 2604 ± 354   |
        | Centróide Pico 3 |  434.90 ± 0.09   |  664.04     | 27.87    | 21091 ± 145   | 19023 ± 215   |


   - Para a placa de chumbo pouco espessa, obtivemos os seguintes dados:
  
     ![Chumbo Pouco Espesso](images/Chumbo_Pouco_Espesso.jpeg)
  

     ### Dados relativos ao espetro de emissão do césio com a Placa de Chumbo pouco espesso
        |  | Valor [Chn]| Valor Calibrado [keV] | FWHM [Chn] | ROI INT | ROI NET |
        |:--------:|:-------:|:----------:|:------:|:-----:|:-----:|
        | Centróide Pico 1 |  59.56 ± 0.07   |  77.36     | 6.98    | 11724 ± 108   | 1778 ± 251   |
        | Centróide Pico 2 |  137.09 ± 0.12   |  198.55     | 16.24    | 19906 ± 141   | 3317 ± 400   |
        | Centróide Pico 3 |  435.15 ± 0.06   |  664.43     | 27.63    | 35637 ± 189   | 33958 ± 237   |


**Todos os ficheiros de dados estão guardados na pasta Data_Files**