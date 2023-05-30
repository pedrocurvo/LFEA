# LogBook Relativo à Realização do Estudo do Detetor Geiger-Müller:

A experiência que em seguida se descreve foi realizada no dia 31 de maio de 2023, com início às 11:30 da manhã e fim às 15:00. O nosso grupo é o 1D e é formado pelo seguintes membros: Estêvão Gomes (ist1102650), Pedro Curvo (ist1102716), Sofia Tété (ist1102633) e Salvador Torpes (ist1102474). LogBook realizado por Sofia Tété.

1. **Estudo do detector:**
   - Ligamos o detetor e começamos por analisar o detetor e perceber que a voltagem a que este se encontrava sujeito se controlava a partir do programa GMX (computador) ao qual o detetor já se encontrava ligado;
   - Em seguida, colocamos a fonte de tálio marcada com L03 (Tl - 204) virada para cima na prateleira 3 do detetor;
   - No programa de aquisição GMX, selecionamos um tempo de 2 segundos por cada intervalo de voltagem e iniciamos as medições nos 25 Volts. Verfificamos que o detetor apenas começa a registar contagens a partir dos 725 V;
   - Agora que realizamos esta aquisição mais bruta de dados, percebemos que o plateau tem inicio perto dos 725 V. Podemos agora realizar uma aquisição mais cuidadosa para o detetar mais precisamente;
   - Iniciamos as medições. Para tal, selecionamos um time-step de 30 segundos para cada voltagem e uma voltagem inicial de 600 V. O objetivo desta etapa é, encontrar as voltagens onde o plateau deste detetor de Geiger Müller começa e termina para que possamos definir a voltagem que iremos utilizar para as seguintes etapas deste trabalho laboratorial;
   - Repetimos o processo com o mesmo time-step e começando na mesmo nos 600 V de modo a obter uma maior precisão nos dados. Obtivemos os seguintes dados:

   | Voltagem (V)      | Contagem 1 | Contagem 2 | 
   |-------------------|------------|------------|
   | 700               | 0          | 0          | 
   | 725               | 0          | 0          |
   | 750               | 549 ± 23   | 1 ± 1      | 
   | 775               | 553 ± 24   | 575 ± 24   | 
   | 800               | 651 ± 26   | 565 ± 24   | 
   | 825               | 651 ± 26   | 626 ± 25   | 
   | 850               | 617 ± 25   | 682 ± 26   | 
   | 875               | 675 ± 26   | 667 ± 26   | 
   | 900               | 687 ± 26   | 666 ± 26   | 
   | 925               | 653 ± 26   | 675 ± 26   | 
   | 950               | 663 ± 26   | 690 ± 26   | 
   | 975               | 673 ± 26   | 685 ± 26   | 
   | 1000              | 736 ± 27   | 707 ± 27   | 
   | 1025              | 767 ± 28   | 738 ± 27   | 
   | 1050              | 796 ± 28   | 764 ± 28   | 
   | 1075              | 701 ± 26   | 746 ± 27   | 
   | 1100              | 754 ± 27   | 782 ± 28   | 
   | 1125              | 737 ± 27   | 785 ± 28   | 
   | 1150              | 750 ± 27   | 740 ± 27   | 
   | 1175              | 757 ± 28   | 810 ± 28   | 
   | 1200              | 775 ± 28   | 770 ± 28   | 
   | Tempo de contagem | 60 s       |            |            

   - Após uma primeira análise destes dados, concluimos que o plateau deste detetor Geiger-Müller se situava entre 800 V e 1200 V. Selecionamos o início do plateau na voltagem para a qual observamos que os dados começavam a comportar-se linearmente e o fim corresponde apenas à última voltagem aplicada pelo sistema. Em seguida, selecionamos uma tensão de 950 V para utilizar no resto deste trabalho, que corresponde a certa de 3/8 do plateau.
   - Com a tensão que escolhemos no ponto anterior, realizamos duas aquisições de 5 segundos com a fonte de tálio virada para cima e duas aquisições com a fonte virada para baixo, totalizando 10 segundos de aquisição para cada um das faces. Para a fonte virada para cima, registamos e contagens e para a fonte virada para baixo registamos e contagens. Obtivemos os seguintes dados:

   |                         | 1º Medição | 2º Medição | Contagens Totais | Taxa de Contagens |
   |-------------------------|------------|------------|------------------|-------------------|
   | Fonte virada para cima  | 117±11     | 118±11     | 235±22           | 23,5±2,2          |
   | Fonte virada para baixo | 2±1        | 1±1        | 3±2              | 0,3±0,2           |
   | Tempo de contagem       | 10 s       |            |                  |                   |

   - De seguida, passámos para a medição do tempo morto do detetor. Para tal utilizámos combinações de três fontes em meia-lua, das quais a 1 e 2 contêm Tálio-204 e a 0 nenhum isótopo radioativo.
   - Fizémos duas medições de 60 segundos para cada combinação de fontes, de modo a ter uma medição total de 120 segundos.
   - Primeiro usámos uma combinação da fonte 0 e 1, tendo obtido 4680 contagens na 1º medição e 4491 contagens na 2º medição.
   - De seguida medimos as contagens para a combinação de fontes 0 e 2, obtendo-se 4561 contagens para a 1º medição e 4618 contagens para a 2º medição.
   - Por fim, usámos a combinação das fontes 1 e 2, tendo-se obtido 8278 contagens para a 1º medição e 8230 contagens para a 2º medição.
   - De seguida encontram-se os dados relativos à medição do tempo morto:
  
   |  | 1º Medição | 2º Medição | Contagens Totais | Taxa de Contagens |
   |-----|---|---|---|---|
   | Meia lua 0-1 | 4680 ± 68 | 4491 ± 67 | 9171 ± 135 | 152,85 ± 1,13 |
   | Meia lua 2-0 | 4561 ± 68 | 4618 ± 67 | 9179 ± 135 | 152,98 ± 1,13 |
   | Lua cheia 2-1 | 8278 ± 91 | 8230 ± 90 | 16508 ± 181 | 275,13 ± 1,51 |
   | Tempo Morto (µs) | 657 ± 42, 34 |  |  |  |
   | Tempo de contagem | 120 s|  |  |  |

   - Para a medição da radiação ambiente, fizémos duas medições de 30 segundos sem utilizar nenhuma fonte, tendo-se obtido 19 contagens em ambas as medições.
   - Obtivemos os seguintes valores:
   - 
  
   | Radiação ambiente | 1º Medição | 2º Medição | Contagens Totais | Taxa de Contagens |
   |-----|---|---|----|----|
   | Contagens | 19 ± 4,36 | 19 ± 4,36 | 38 ± 8,72 | 0,63 ± 0,15 |
   | Tempo de contagem | 60 s |  |  |  |

2. **Estudo da eficiência do detector:**
   - Com objetivo de estudar  eficiência dos betas colocamos uma fonte de tálio que tem betas muito energéticos. Queremos concluir se as placas de aluminio bloqueiam os betas do tálio. Caso os bloqueiem, também bloquearão os do césio dado que estes são menos energéticos. 
   - Para isso, colocamos na prateleira 3 a fonte de tálio e na prateleira 2 uma placa de aluminio totalmente tapada. Realizámos 30 segundos de aquisição de dados duas vezes na tensão de 950V e obtivemos, respetivamente, 16 e 17 contagens. Verificamos que as contagens obtidas se assemelham às contagens obtidas para a radiação ambiente, pelo que concluimos que a placa de aluminio bloqueia os betas do tálio.
  
   
3. **Estudo da intensidade da radiação com a distância:**
   - Começamos por colocar a fonte de césio virada para cima no suporte
   - Para cada uma das prateleiras 1 a 5, realizamos 30 segundos de aquisição de dados duas vezes para cada prateleira na tensão de 950V. Para cada medição, colocamos na prateleira imediatamente acima à prateleira onde de encontrava o césio uma placa de alumínio totalmente tapada com o objetivo de bloquear a radiação beta;
   - Em seguida, repetimos o procedimento anterior, mas desta vez colocamos uma placa de alumínio não totalmente tapada, de modo a controlar o ângulo sólido. A placa de alumínio tinha uma abertura de diâmetro igual a (7,25±0,05) mm, que foi medido recorrendo a uma craveira;
   - Os dados obtidos foram os seguintes:

   | Com Aluminio fechado |            |            |           |
   |--------------|------------|------------|-----------|
   | Prateleira   | Contagem 1 | Contagem 2 | Total     |
   | 1            | 1193 ± 35  | 1230 ± 35  | 2423 ± 70 |
   | 2            | 609 ± 25   | 537 ± 23   | 1146 ± 48 |
   | 3            | 410 ± 20   | 434 ± 21   | 844 ± 41  |
   | 4            | 332 ± 18   | 276 ± 17   | 608 ± 35  |
   | 5            | 250 ± 16   | 256 ± 16   | 506 ± 32  |

   | Com Aluminio com orifício |  |  |  |
   |---|---|---|---|
   | Prateleira | Contagem 1 | Contagem 2 | Total |
   | 1 | 21840 ± 148 | 21748 ± 147 | 43588 ± 295 |
   | 2 | 12911 ± 114 | 13217 ± 115 | 26128 ± 229 |
   | 3 | 5741 ± 76 | 5894 ± 77 | 11635 ± 153 |
   | 4 | 2181 ± 47 | 2299 ± 48 | 4480 ± 95 |
   | 5 | 1794 ± 42 | 1805 ± 42 | 3599 ± 84 |
   - 
4. **Estudo da atenuação de partículas na matéria:**
    - Começamos por colocar a fonte de césio virada para cima no suporte. Colocamos o césio na terceira prateleira com uma placa de alumínio totalmente fechada imediatamente acima, de modo a apenas deixar passar a radiação gamma proveninente do césio;
   - Na prateleira zero colocamos uma placa de alumínio com orfício de diâmetro igual a (7,50±0,05) mm, que foi medido recorrendo a uma craveira. Fomos tapando o orifício da placa que se encontrava na prateleira com 9 materiais diferentes e, para cada um deles, realizámos duas vezes 30 segundos de aquisição de dados na tensão de 950V;
   - Em seguida, encontram-se os dados obtidos para cada um dos materiais utilizados e em cada uma das medições feitas

5. 


