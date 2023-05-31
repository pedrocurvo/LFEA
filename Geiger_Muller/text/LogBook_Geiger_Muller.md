# LogBook Relativo à Realização do Estudo do Detetor Geiger-Müller:

A experiência que em seguida se descreve foi realizada no dia 31 de maio de 2023, com início às 11:30 da manhã e fim às 15:00. O nosso grupo é o 1D e é formado pelo seguintes membros: Estêvão Gomes (ist1102650), Pedro Curvo (ist1102716), Sofia Tété (ist1102633) e Salvador Torpes (ist1102474). LogBook realizado por Sofia Tété.

1. **Estudo do detector:**
   - Ligamos o detetor e começamos por analisar o detetor e perceber que a voltagem a que este se encontrava sujeito se controlava a partir do programa GMX (computador) ao qual o detetor já se encontrava ligado;
   - Em seguida, colocamos a fonte de tálio marcada com L03 (Tl - 204) virada para cima na prateleira 3 do detetor;
   - No programa de aquisição GMX, selecionamos um tempo de 2 segundos por cada intervalo de voltagem e iniciamos as medições nos 25 Volts. Verfificamos que o detetor apenas começa a registar contagens a partir dos 725 V;
   - Agora que realizamos esta aquisição mais bruta de dados, percebemos que o plateau tem inicio perto dos 725 V. Podemos agora realizar uma aquisição mais cuidadosa para o detetar mais precisamente;
   - Iniciamos as medições. Para tal, selecionamos um time-step de 30 segundos para cada voltagem e uma voltagem inicial de 600 V. O objetivo desta etapa é, encontrar as voltagens onde o plateau deste detetor de Geiger Müller começa e termina para que possamos definir a voltagem que iremos utilizar para as seguintes etapas deste trabalho laboratorial;
   - Repetimos o processo com o mesmo time-step e começando na mesmo nos 600 V de modo a obter uma maior precisão nos dados. Obtivemos os seguintes dados:

   | Voltagem (V)     | Contagem 1 | Incerteza 1 | Contagem 2 | Incerteza 2 | N    | dN          | Taxa        | Incerteza da Taxa | True Rate   | d(True Rate) |
   |------------------|------------|-------------|------------|-------------|------|-------------|-------------|-------------------|-------------|--------------|
   | 700              | 0          | 0           | 0          | 0           | 0    | 0           | 0           | 0                 | 0           | 0,157631974  |
   | 725              | 0          | 0           | 0          | 0           | 0    | 0           | 0           | 0                 | 0           | 0,157631974  |
   | 750              | 549        | 23,43074903 | 459        | 21,42428529 | 1008 | 44,85503431 | 16,8        | 0,747583905       | 17,14850345 | 0,811944756  |
   | 775              | 553        | 23,51595203 | 575        | 23,97915762 | 1128 | 47,49510965 | 18,8        | 0,791585161       | 19,43641234 | 0,864498529  |
   | 800              | 651        | 25,51470164 | 565        | 23,76972865 | 1216 | 49,28443029 | 20,26666667 | 0,821407172       | 21,13715965 | 0,901040066  |
   | 825              | 651        | 25,51470164 | 626        | 25,01999201 | 1277 | 50,53469365 | 21,28333333 | 0,842244894       | 22,32768388 | 0,926825902  |
   | 850              | 617        | 24,8394847  | 682        | 26,11512971 | 1299 | 50,95461441 | 21,65       | 0,849243574       | 22,7594095  | 0,935629576  |
   | 875              | 675        | 25,98076211 | 667        | 25,82634314 | 1342 | 51,80710525 | 22,36666667 | 0,863451754       | 23,60687359 | 0,953486449  |
   | 900              | 687        | 26,21068484 | 666        | 25,8069758  | 1353 | 52,01766065 | 22,55       | 0,866961011       | 23,82444351 | 0,957937729  |
   | 925              | 653        | 25,55386468 | 675        | 25,98076211 | 1328 | 51,53462679 | 22,13333333 | 0,858910447       | 23,330425   | 0,947751043  |
   | 950              | 663        | 25,74878638 | 690        | 26,26785107 | 1353 | 52,01663745 | 22,55       | 0,866943958       | 23,82444351 | 0,9579194    |
   | 975              | 673        | 25,94224354 | 685        | 26,17250466 | 1358 | 52,1147482  | 22,63333333 | 0,868579137       | 23,92344396 | 0,959988134  |
   | 1000             | 736        | 27,12931993 | 707        | 26,5894716  | 1443 | 53,71879153 | 24,05       | 0,895313192       | 25,61656248 | 0,994236325  |
   | 1025             | 767        | 27,69476485 | 738        | 27,16615541 | 1505 | 54,86092026 | 25,08333333 | 0,914348671       | 26,86371167 | 1,018979841  |
   | 1050             | 796        | 28,21347196 | 764        | 27,64054992 | 1560 | 55,85402188 | 26          | 0,930900365       | 27,97876218 | 1,040751114  |
   | 1075             | 701        | 26,47640459 | 746        | 27,31300057 | 1447 | 53,78940516 | 24,11666667 | 0,896490086       | 25,69671212 | 0,995770547  |
   | 1100             | 754        | 27,45906044 | 782        | 27,96426291 | 1536 | 55,42332334 | 25,6        | 0,923722056       | 27,49118154 | 1,031277838  |
   | 1125             | 737        | 27,14774392 | 785        | 28,01785145 | 1522 | 55,16559537 | 25,36666667 | 0,91942659        | 27,20748478 | 1,025649204  |
   | 1150             | 750        | 27,38612788 | 740        | 27,20294102 | 1490 | 54,58906889 | 24,83333333 | 0,909817815       | 26,56103242 | 1,013054036  |
   | 1175             | 757        | 27,51363298 | 810        | 28,46049894 | 1567 | 55,97413193 | 26,11666667 | 0,932902199       | 28,12126993 | 1,043420011  |
   | 1200             | 775        | 27,83882181 | 770        | 27,74887385 | 1545 | 55,58769567 | 25,75       | 0,926461594       | 27,67383995 | 1,034878463  |
   | Tempode Contagem | 60 s       |             |            |             |      |             |             |                   |             |              |

   - Após uma primeira análise destes dados, concluimos que o plateau deste detetor Geiger-Müller se situava entre 800 V e 1200 V. Selecionamos o início do plateau na voltagem para a qual observamos que os dados começavam a comportar-se linearmente e o fim corresponde apenas à última voltagem aplicada pelo sistema. Em seguida, selecionamos uma tensão de 950 V para utilizar no resto deste trabalho, que corresponde a certa de 3/8 do plateau.
   - Com a tensão que escolhemos no ponto anterior, realizamos duas aquisições de 5 segundos com a fonte de tálio virada para cima e duas aquisições com a fonte virada para baixo, totalizando 10 segundos de aquisição para cada um das faces. Para a fonte virada para cima, registamos e contagens e para a fonte virada para baixo registamos e contagens. Obtivemos os seguintes dados:



   - 
2. **Estudo da eficiência do detector:**
   - ...
3. **Estudo da intensidade da radiação com a distância:**
   - ...
4. **Estudo da atenuação de partículas na matéria:**
   - ...
5. 

![this is a image ](../../Gama/Graphs/Espetro_Ambiente_Smoothed.png){ width=150px }
// usem ../pngs/ para as imagens que estão na pasta pngs os .. voltam atras e entram na pasta 
// o { width=150px } é para definir o tamanho da imagem nao aparece na preview mas aparece no pdf
