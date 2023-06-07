# Logbook - Radiação Alfa #

### Trabalho realizado a 25 de maio de 2023
### Logbook por Rodrigo Laia, ist1102674


**1-** Ligámos o espectómetro alfa e ao osciloscópio e ao MCA através da saída energy do espectómetro.

**2-** Ligámos a crate e o osciloscópio e pusemos a amostra Am-241 dentro do espectrómetro na prateleira 4.

**3-** Ligámos a bomba de vácuo e esperamos um minuto enquanto o espectómetro estava no modo vent.

**4-** Pusemos o espectómetro no modo vacuum durante um minuto.

**5-** Mudamos o espectómetro para o modo hold e ligamos o bias. Observamos sinais no osciloscópio provenientes da radiação emitada pela amostra.

**6-** Para diferentes energy ranges fizemos uma aquisição de 120s e registamos o centroid.

Energy Range (MeV)| ROI NET (Chn)
:--:|:--:
3-8| 41 228 ± 228
4-7 | 41 049 ± 247
3-5 | ruido
4-6 | 40 286 ± 268


Nota: não se vê nada no range 3-5 MeV porque as energias dos picos principais do amerício-241 são superiores a 5 MeV, dado que fomos buscar ao site http://nucleardata.nuclear.lu.se/toi/ 

**7-** A meio do processo (entre os 3-5 MeV e os 4-6 MeV) decidimos refazer o vácuo porque sabemos que o isolamento não é perfeito.

**8-** Em teoria como os picos principais do amerício-241 estão localizados entre os 5,5 e os 6 MeV a janela seria a 5-7 MeV mas ao fazermos a aquisição parecia ser a 4-6 MeV. Pensamos que isto podia dever-se à perda de qualidade do vácuo, logo voltamos a fazer vácuo e repetimos a aquisição.

Energy Range (MeV)| ROI NET (Chn)
:--:|:--:
5-7| 40 472 ± 266
6-8 | ruido

**9-** Desta vez já se viu melhor a distinção entre picos - escolhemos esta janela (5-7MeV).

**10-** Seguindo o procedimento anterior, fizemos vácuo no espectómetro.

**11-** Fizemos uma aquisição de 180s e guardamos o dados obtidos no ficheiro pimam.asc

Parâmetros | Dados 
:--:|:--:
ROI Int | 40 996 ± 202
ROI Net | 20 796 ± 339
Centroid | 367.49 Chn
FwHm | 12.51

**12-** Tiramos o vácuo e depois tirámos a fonte.

**13-** Voltamos a fazer vácuo e desta vez em vez de ligar o bias ligamos o pulser e para 6 valores de energia diferentes fizemos uma aquisição de 140s no MCA. Os resultados encontram-se na seguinte tabela:


| Energia no Pulser (MeV) | ROI Int  | ROI Net  | Centroid (Chn) | FwHm | Tempo de Aquisição |
|:---:|:---:|:---:|:---:|:---:|:---:|
|(5,00 ± 0,01) MeV| 9 888 ± 99 | 9 842 ± 101 |289,76| 7,19 |140s|
|(5,20 ± 0,01) MeV| 13 416 ± 116 | 13 375 ± 118 |  406,51 | 15,46 |150s|
|(5,40 ± 0,01) MeV| 12 745 ± 113 | 12 718 ± 114 |  521,56 | 7,12  |142s|
|(5,60 ± 0,01) MeV| 12 667 ± 113 | 12 606 ± 116 |  633,11 | 12,26 |142s|
|(5,80 ± 0,01) MeV| 12 493 ± 112 | 12 459 ± 113 |  748,37 | 7,68  |140s|
|(6,00 ± 0,01) MeV| 12 481 ± 112 | 12 386 ± 116 |  864,53 | 13,90 |140s|


**14-** Para manter um vácuo mais consistente entre aquisições decidimos fazer vácuo de duas em duas aquisições. **

**15-** Apesar de termos planeado fazer aquisições de 140s na aquisição de 5,20 MeV sem querer o tempo passou dos 140s mas como a grandeza que nos interessa medir é a taxa não há problema. Decidimos então registar também o tempo de aquisição.

**16-** Tentamos encontrar o valor na escala do pulser para o qual estamos no canal que medimos inicialmente para o maior pico do amerício - (5,14 ± 0,01) MeV.

**17-** Voltámos a colocar a fonte na espectómetro e fizemos vácuo outra vez.

**18-** Fizemos uma aquisição de 180s e guardamos o ficheiro como pim_am1.asc

Parâmetros | Dados 
:--:|:--:
ROI Int | 43 392 ± 208
ROI Net | 24 849 ± 324
Centroid | 387,04 Chn
FwHm | 16,78


**19-** Repetimos o processo e guardamos os ficheiros como pim_am2.asc e pim_am3.asc

**20-** Desligamos a crate e mudamos o cabo de energy para linear amperation.

**21-** Fizemos vácuo e voltamos a fazer uma aquisição de 120s com o amerício no espectómetro. Guardamos o ficheiro como pimam1lin.asc

**22-** Fizemos vácuo novamente.

**23-** Pusemos o valor no pulser a 5 MeV. Fizemos uma aquisição de 60s 

**24-** Estavam dois picos no MCA e por isso apercebemo-nos que nos esquecemos de tirar a amostra.

**25-** Tiramos a amostra e fizemos vácuo novamente.

| Energia no Pulser (MeV) | ROI Int  | ROI Net  | Centroid (Chn) |Tempo de Aquisição |
|:---:|:---:|:---:|:---:|:---:|
|(5,00 ± 0,01) MeV| 5 583 ± 75 | 5 570 ± 101 | 667,33| 62s|
|(5,20 ± 0,01) MeV| 5 379 ± 73 | 5 292 ± 74  | 695,10| 60s|
|(5,40 ± 0,01) MeV| 5 288 ± 73 | 4 991 ± 75  | 721,90| 60s|
|(5,60 ± 0,01) MeV| 5 361 ± 73 | 5 137 ± 76  | 748,59| 60s|
|(5,80 ± 0,01) MeV| 5 376 ± 73 | 5 317 ± 74  | 774,75| 60s|

**26-** Tiramos o vácuo e adquirimos durante 180s e guardamos como pim_am_ar.asc

**27-** Para medir a incerteza do botão do pulser, a professora sugeriu colocarmos todos o botão na mesma posição à vez e medirmos o centróide.

|Pessoa | Centroid |
|:---:|:---:|
Laia | 667,87 Chn
Nuno | 657.59 Chn
Belas | 667,59 Chn
Joana | 667,98 Chn

**28-** Passamos os ficheiros todos da disquete para a pen.




