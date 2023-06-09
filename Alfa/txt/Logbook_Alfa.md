# LogBook Relativo à Realização do Estudo da Radiação Alfa 

A experiência que em seguida se descreve foi realizada no dia 5 de junho de 2023, com início às 8:00 da manhã e fim às 11:00. O nosso grupo é o 1D e é formado pelo Estêvão Gomes (ist1102650), o Pedro Curvo (ist1102716), a Sofia Tété (ist1102633) e o Salvador Torpes (ist1102474). LogBook realizado por Estêvão Gomes.

1. **Espectroscopia de precisão de fonte emissora $\alpha$:**
   - Começamos por ligar o computador para ligar o MCA;
   - Em seguida pedimos as fontes radioativas ao professor. Descobrimos que a fonte de polónio já tinha morrido no entanto a de amerício não, pelo que foi esta que utilizamos no decorrer deste trabalho experiemntal;
   - O professor colocou a fonte dentro do detetor SOLOIST na quarta prateleira e em seguida ligamos a bomba de vácuo;
   - Viramos o dial para vacuum pump e esperamos um minuto até que a bomba parasse de fazer barulho. Desligamos a bomba e viramos o dial para Hold;
   - Certificamo-nos que, uma vez que o nosso detetor possui dois amplificadores (um linear e o outro de janela), o output para o computador se encontrava ligado ao amplificador de janela; 
   - Ligamos a tensão bias no detetor para poder iniciar a aquisição de dados exoperimentais;
   - Fomos selecionando diferentes ranges de energia para o amplificador de janela do detetor. Realizamos uma aquisição de dados no MCA rápida durante a qual fomos mudando o energy range e observando onde se encontrava o pico de energia da fonte. Observamos que o espetro de radiação alfa do amerício continha um pico bem definido e concluimos que a melhor range para utilizarmos durante a experiência é a de 5-7 MeV;
   - Depois de escolhermos este range de energia, realizamos uma aquisição de dados no MCA durante 120 segundos com o pulser desligado. Guardamos os dados obtidos para posterior análise. Verificamos que se observam nitiditamente três picos de energia sobrepostos no espetro deste elemento na zona dos 400 Chn;
   - Desligamos o bias e ligamos o pulser do detetor;
   - Em seguida, com o objetivo de calibrar o sistema recorrendo a um pulser, realizamos uma aquisição de dados no MCA. A cada 30 segundos, alteramos a energia do pulser e repetimos o processo para três valores diferentes da energia. Nestes espetros, observamos os diferentes picos do pulser bem como, com maior intensidade, o pico de emissão do amerício. No fim, retiramos dados para cada um deles, obtendo os seguintes resultados:
  
    Energia no Pulser (MeV) | ROI Int  | ROI Net | Centroid (Chn) | FWHM (Chn) | Tempo de Aquisição |
   |:------:|:---:|:---:|:---:|:--:|:----:|
   |5,00 ± 0,01| 2668 ± 52 | 2533 ± 58 | 289,45 ± 0,07 | 8,26 |30s|
   |5,50 ± 0,01| 2746 ± 52 | 2623 ± 63 | 580,59 ± 0,15 | 17,59 |30s|
   |6,00 ± 0,01| 2547 ± 50 | 2480 ± 56 | 872,04 ± 0,13 | 15,18  |30s|

   - Repetimos o procedimento do ponto anterior, mas desta vez realizmaos a aquisição de dados durante 120 segundos para cada valor da energia do pulser. Por sugestão do professor, realizamos uma nova medição para um uma energia do pulser de 5,75 MeV. Obtivemos os seguintes valores:
  
    Energia no Pulser (MeV) | ROI Int  | ROI Net | Centroid (Chn) | FWHM (Chn) | Tempo de Aquisição |
   |:------:|:---:|:---:|:---:|:--:|:----:|
   |5,00 ± 0,01| 10499 ± 102 | 9676 ± 125 | 290,46 ± 0,04 | 10,07 |120s|
   |5,50 ± 0,01| 10526 ± 103 | 10197 ± 110 | 581,59 ± 0,03 | 7,02 |120s|
   |5,75 ± 0,01| 10529 ± 103 | 10320 ± 109 | 726,21 ± 0,03 | 7,71  |120s|
   |6,00 ± 0,01| 10538 ± 103 | 10347 ± 109 | 875,37 ± 0,03 | 7,58  |120s|

2. **Estudo da atenuação das partículas $\alpha$ na matéria:**
   - Começamos por desligar o output do detetor no amplificador de janela e ligá-lo ao amplificador linear;
   - Em seguida, realizamos uma aquisição de dados no MCA durante 240 segundos com o pulser desligado e mantendo o vácuo. Dividimos a aquisição em duas partes, cada uma de 120 segundos uma vez que, ao longo do tempo, o detetor aquece e pode alterar a largura dos picos (sugestão do professor). Guardamos os dados obtidos;
   - Em seguida, com o objetivo de calibrar o sistema, realizamos uma aquisição de dados no MCA com o pulser ligado e com a câmara ainda em vácuo. A cada 120 segundos, alteramos a energia do pulser e repetimos o processo para quatro valores diferentes da energia. No fim, retiramos dados para cada um deles, obtendo os seguintes resultados:
  
    Energia no Pulser (MeV) | ROI Int  | ROI Net | Centroid (Chn) | FWHM (Chn) | Tempo de Aquisição |
   |:------:|:---:|:---:|:---:|:--:|:----:|
   |5,00 ± 0,01| 10547 ± 103 | 10344 ± 106 | 667,90 ± 0,01 | 3,53 |120s|
   |5,50 ± 0,01| 10490 ± 102 | 10448 ± 103 | 735,94 ± 0,01 | 2,50 |120s|
   |5,75 ± 0,01| 10591 ± 103 | 10567 ± 103 | 769,51 ± 0,01 | 2,48 |120s|
   |6,00 ± 0,01| 10417 ± 102 | 10392 ± 102 | 804,45 ± 0,01 | 2,51 |120s|

   - Retiramos o vácuo da câmara;
   - Realizamos uma aquisição de dados no MCA durante 240 segundos com o pulser desligado e com ar na câmara. Dividimos, mais uma vez, a aquisição em duas partes, cada uma de 120 segundos. Guardamos os dados obtidos;
   - Abrimos a câmara do detetor e mudamos a fonte para a prateleira 8. 
   - Realizamos uma aquisição de dados no MCA durante 240 segundos com o pulser desligado, a fonte na prateleira 8 e sem vácuo na câmara. Guardamos os dados obtidos;
   - Voltamos a colocar vácuo na câmara com recurso à bomba de vácuo;
   - Realizamos uma aquisição de dados no MCA durante 240 segundos com o pulser desligado, a fonte na prateleira 8 e com vácuo na câmara. Guardamos os dados obtidos;