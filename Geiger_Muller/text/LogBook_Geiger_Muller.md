# LogBook Relativo à Realização do Estudo do Detetor Geiger-Müller:

A experiência que em seguida se descreve foi realizada no dia 31 de maio de 2023, com início às 11:30 da manhã e fim às 15:00. O nosso grupo é o 1D e é formado pelo seguintes membros: Estêvão Gomes (ist1102650), Pedro Curvo (ist1102716), Sofia Tété (ist1102633) e Salvador Torpes (ist1102474). LogBook realizado por Sofia Tété.

1. **Estudo do detector:**
   - Ligamos o detetor e começamos por analisar o detetor e perceber que a voltagem a que este se encontrava sujeito se controlava a partir do programa GMX (computador) ao qual o detetor já se encontrava ligado;
   - Em seguida, colocamos a fonte de tálio marcada com L03 (Tl - 204) virada para cima na prateleira 3 do detetor;
   - No programa de aquisição GMX, selecionamos um tempo de 2 segundos por cada intervalo de voltagem e iniciamos as medições nos 25 Volts. Verfificamos que o detetor apenas começa a registar contagens a partir dos 725 V;
   - Agora que realizamos esta aquisição mais bruta de dados, percebemos que o plateau tem inicio perto dos 725 V. Podemos agora realizar uma aquisição mais cuidadosa para o detetar mais precisamente;
   - Iniciamos as medições. Para tal, selecionamos um time-step de 30 segundos para cada voltagem e uma voltagem inicial de 600 V. O objetivo desta etapa é, encontrar as voltagens onde o plateau deste detetor de Geiger Müller começa e termina para que possamos definir a voltagem que iremos utilizar para as seguintes etapas deste trabalho laboratorial;
   - Repetimos o processo com o mesmo time-step e começando na mesmo nos 600 V de modo a obter uma maior precisão nos dados. Obtivemos os seguintes dados:

   | Voltagem (V) | Contagem 1 | Incerteza 1 | Contagem 2 | Incerteza 2 | N | dN | Taxa | Incerteza da Taxa | True Rate | d(True Rate) |
   |---|---|---|---|---|---|---|---|---|---|---|
   | 700 | 0 | 0,00 | 0 | 0,00 | 0,00 | 0,00 | 0,00 | 0,00 | 0,00 | 0,00 |
   | 725 | 0 | 0,00 | 0 | 0,00 | 0,00 | 0,00 | 0,00 | 0,00 | 0,00 | 0,00 |
   | 750 | 549 | 23,43 | 1 | 1,00 | 550,00 | 24,43 | 9,17 | 0,41 | 8,59 | 0,43 |
   | 775 | 553 | 23,52 | 575 | 23,98 | 1128,00 | 47,50 | 18,80 | 0,79 | 18,40 | 0,81 |
   | 800 | 651 | 25,51 | 565 | 23,77 | 1216,00 | 49,28 | 20,27 | 0,82 | 19,91 | 0,85 |
   | 825 | 651 | 25,51 | 626 | 25,02 | 1277,00 | 50,53 | 21,28 | 0,84 | 20,95 | 0,87 |
   | 850 | 617 | 24,84 | 682 | 26,12 | 1299,00 | 50,95 | 21,65 | 0,85 | 21,33 | 0,87 |
   | 875 | 675 | 25,98 | 667 | 25,83 | 1342,00 | 51,81 | 22,37 | 0,86 | 22,07 | 0,89 |
   | 900 | 687 | 26,21 | 666 | 25,81 | 1353,00 | 52,02 | 22,55 | 0,87 | 22,26 | 0,89 |
   | 925 | 653 | 25,55 | 675 | 25,98 | 1328,00 | 51,53 | 22,13 | 0,86 | 21,83 | 0,88 |
   | 950 | 663 | 25,75 | 690 | 26,27 | 1353,00 | 52,02 | 22,55 | 0,87 | 22,26 | 0,89 |
   | 975 | 673 | 25,94 | 685 | 26,17 | 1358,00 | 52,11 | 22,63 | 0,87 | 22,34 | 0,89 |
   | 1000 | 736 | 27,13 | 707 | 26,59 | 1443,00 | 53,72 | 24,05 | 0,90 | 23,80 | 0,92 |
   | 1025 | 767 | 27,69 | 738 | 27,17 | 1505,00 | 54,86 | 25,08 | 0,91 | 24,87 | 0,94 |
   | 1050 | 796 | 28,21 | 764 | 27,64 | 1560,00 | 55,85 | 26,00 | 0,93 | 25,82 | 0,96 |
   | 1075 | 701 | 26,48 | 746 | 27,31 | 1447,00 | 53,79 | 24,12 | 0,90 | 23,87 | 0,92 |
   | 1100 | 754 | 27,46 | 782 | 27,96 | 1536,00 | 55,42 | 25,60 | 0,92 | 25,40 | 0,95 |
   | 1125 | 737 | 27,15 | 785 | 28,02 | 1522,00 | 55,17 | 25,37 | 0,92 | 25,16 | 0,95 |
   | 1150 | 750 | 27,39 | 740 | 27,20 | 1490,00 | 54,59 | 24,83 | 0,91 | 24,61 | 0,94 |
   | 1175 | 757 | 27,51 | 810 | 28,46 | 1567,00 | 55,97 | 26,12 | 0,93 | 25,94 | 0,96 |
   | 1200 | 775 | 27,84 | 770 | 27,75 | 1545,00 | 55,59 | 25,75 | 0,93 | 25,56 | 0,95 |
   | Tempo de contagem |  | 60 s |  |  |  |  |  |  |  |  |
   |  |  |  |  |  |  |  |  |  |  |  |

   - Após uma primeira análise destes dados, concluimos que o plateau deste detetor Geiger-Müller se situava entre 800 V e 1200 V. Selecionamos o início do plateau na voltagem para a qual observamos que os dados começavam a comportar-se linearmente e o fim corresponde apenas à última voltagem aplicada pelo sistema. Em seguida, selecionamos uma tensão de 950 V para utilizar no resto deste trabalho, que corresponde a certa de 3/8 do plateau.
   - Com a tensão que escolhemos no ponto anterior, realizamos duas aquisições de 5 segundos com a fonte de tálio virada para cima e duas aquisições com a fonte virada para baixo, totalizando 10 segundos de aquisição para cada um das faces. Para a fonte virada para cima, registamos e contagens e para a fonte virada para baixo registamos e contagens. Obtivemos os seguintes dados:



   - De seguida, passámos para a medição do tempo morto do detetor. Para tal utilizámos combinações de três fontes em meia-lua, das quais a 1 e 2 contêm Tálio-204 e a 0 nenhum isótopo radioativo.
   - Fizémos duas medições de 60 segundos para cada combinação de fontes, de modo a ter uma medição total de 120 segundos.
   - Primeiro usámos uma combinação da fonte 0 e 1, tendo obtido 4680 contagens na 1º medição e 4491 contagens na 2º medição.
   - De seguida medimos as contagens para a combinação de fontes 0 e 2, obtendo-se 4561 contagens para a 1º medição e 4618 contagens para a 2º medição.
   - Por fim, usámos a combinação das fontes 1 e 2, tendo-se obtido 8278 contagens para a 1º medição e 8230 contagens para a 2º medição.
   - Para a medição da radiação ambiente, fizémos duas medições de 30 segundos sem utilizar nenhuma fonte, tendo-se obtido 19 contagens em ambas as medições.
1. **Estudo da eficiência do detector:**
   - ...
2. **Estudo da intensidade da radiação com a distância:**
   - ...
3. **Estudo da atenuação de partículas na matéria:**
   - ...
4. 

![this is a image ](../../Gama/Graphs/Espetro_Ambiente_Smoothed.png){ width=150px }
// usem ../pngs/ para as imagens que estão na pasta pngs os .. voltam atras e entram na pasta 
// o { width=150px } é para definir o tamanho da imagem nao aparece na preview mas aparece no pdf
