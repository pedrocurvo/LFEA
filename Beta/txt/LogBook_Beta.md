# LogBook Relativo à Realização do Estudo da Espetroscopia Beta  

A experiência que em seguida se descreve foi realizada no dia 7 de junho de 2023 no laboratório LFE II no IST, com início às 11:30 da manhã e fim às 15:00. O nosso grupo é o 1D e é formado pelo seguintes membros: Estêvão Gomes (ist1102650), Pedro Curvo (ist1102716), Sofia Tété (ist1102633) e Salvador Torpes (ist1102474). LogBook realizado por Pedro Curvo.

1. **Calibração:**
   - Objetivo: calibrar o sistema recorrendo a um pulser que emite pulsos de energia 620 keV, o que corresponde ao pico de conversão interna do Cs-137, elemento cujo espetro também vamos estudar;
   - Começamos por ligar o computador bem como abrir o programa de aquisição de dados MCA;
   - De seguida, pedimos ao professor as fontes radioativas necessárias para a realização da experiência, sendo elas: o Césio Cs-137 (marcado com L07), o Tálio Tl-204 (marcado com L06) e o Bismuto Bi-207 (marcado com L14);
   - Ligamos o detetor ao osciloscópio (saída lamp out) e ao MCA;
   - Colocamos a fonte de Cs-137 dentro do detetor na prateleira 3 e fechamos a câmara. Ligamos a bomba de vácuo e selecionamos o modo Vent durante um minuto. Mudamos o dial para o modo pump e esperámos que o vácuo se establecesse durante 2 minutos;
   - Por fim, selecionamos o modo Hold e desligamos a bomba de vácuo;
   - Ligamos o BIAS (de modo a ativar o campo elétrico do detetor de silício) e iniciamos a aquisição de dados no MCA durante 10 minutos com o objetivo de obter o espetro de energia do Cs-137;
   - Enquanto os dados eram adquiridos, observamos o sinal no osciloscópio e medimos a sua amplitude, obtendo o seguinte valor:
   $$\text{A}=0.88\pm0.01 V$$  

   ||
   |:---:|
   ![Sinal do Césio no Osciloscópio](images/osciloscopio.jpg ){width=50%} |
   
   - Durante a aquisição, aproveitamos também para fazer uma análise qualitativa do sinal: conseguimos, no espetro do Cs-137, observar o espetro de emissão contínua do eletrão do decaimento beta, seguida do pico de conversão interna do césio o qual sabemos que corresponder a 620 keV. Não detetamos o pico de 660 keV da desexcitação nuclear do bário uma vez que este detetor é muito pouco espesso e por isso os fotões gama não integram com ele, não sendo detetados com eficiência significativa;
   - No fim da aquisição, utilizamos o MCA para retirar dados de ajuste do pico de energia do Cs-137 correspondente à energia libertada na transição nuclear e à de conversão interna, obtendo os seguintes valores:

    Pico de Conversão Interna do Cs-137  | ROI Int  | ROI Net | Centroid (Chn) | FWHM (Chn) | Tempo de Aquisição (s) |
    |:---------:|:---:|:---:|:-----:|:--:|:----:|
    || 14745 ± 121 | 5888 ± 184 | 116.56 ± 0.03 | 5.91 |600|

   - Guardamos os dados do espetro obtido no MCA para posterior análise;
   - Retiramos o vácuo da câmara e retiramos a fonte de Cs-137 do detetor;
   - Voltamos a colocar a câmara em vácuo com o BIAS desligado mas desta vez sem nenhuma fonte radioativa dentro;
   - Ligamos o Pulser e realizamos aquisições de dados para diferentes valores de energia dos pulsos emitidos pelo Pulser de modo a mais tarde podemos construir uma reta de ajuste para a calibação. Para tal, realizámos aquisições de 1 minuto cada com diferentes energias no pulser, começando com a energia de 0.1 MeV e aumentando de 0.1 MeV em 0.1 MeV até 1.1 MeV, obtendo 11 picos no total. Devido à reduzida largura de cada pico de emissão no espetro observado no MCA, o programa não consegue realizar o ajuste e calcular um valor para cada centróide. Assim sendo, guardamos apenas os dados obtidos no espetro para posterior análise;
   - Desligamos o vácuo;
2. **Limite Cinemático:**  
   - Objetivo: determinar a energia máxima que um eletrão resultante do decaimento $\beta$- do Tl-204 pode ter;
   - Colocamos a fonte de tálio dentro do detetor e fechamos a câmara;
   - Repetimos o processo de colocar vácuo na câmara;
   - Ligamos o BIAS e iniciamos a aquisição de dados no MCA durante 600 segundos com o objetivo de obter o espetro de energia do Tl-204;
   - Realizamos a análise quantitativa do espetro: conseguimos observar o espetro contínuo do decaimento beta do tálio. Não observámos mais picos, dado que neste caso não há um pico de conversão interna.  

   ||
   |:---:|
   ![Espetro do Tl-204](images/espetro_Tl.jpg ){align="center" width="50%"}|

   - Guardamos os dados do espetro obtido no MCA para posterior análise;
   - Retirámos o vácuo e retiramos a fonte de tálio do detetor;
3. **Estudo da fonte de Bismuto:**  
   - Objetivo: estudar o espetro de energia do Bi-207;
   - Colocamos a fonte de bismuto dentro do detetor e fechamos a câmara;
   - Repetimos o processo de colocar vácuo na câmara;
   - Ligamos o BIAS e iniciamos a aquisição de dados no MCA durante 600 segundos com o objetivo de obter o espetro de energia do Bi-207;
   - Relizámos a análise qualitativa do espetro: verificámos a existência de um pico inicial alto, de um segundo pico mais baixo e achatado e um terceiro pico mais alto e estreito. Por último, vimos também 2 picos finos, mais baixos que os anteriores. O primeiro pico observado no espetro do bismuto é um pico de raios-X que se deve aos eletrões de Auger emitidos nas desexcitações do átomo. O segundo pico deve-se a anomalias do detetor. No decaimento beta+, o bismuto transforma-se num filho cujo núcleo é instável. A desexcitação deste núcleo tem duas fases ocorrendo a libertação de energia que provoca a conversão interna, que estão representados nos três picos restantes. Mais uma vez não detetamos os picos da radiação gama, dado que o detetor tem eficiência gama muito reduzida. 

   ||
   |:---:|
   ![Espetro do Bi-207](images/espetro_Bi.jpg ){align="center" width="30%"} |

   - Para os picos do espetro não obtivemos dados de ajuste do MCA, dado que o ajuste não é gaussiano, pelo que apenas os guardámos em ficheiros de dados para posterior análise.
   - Retirámos o vácuo e retiramos a fonte de bismuto do detetor;
4. **Estudo do Detetor:**  
   - Objetivo: estudar o efeito do ambiente, as resoluções de energia e a eficiência do detetor para partículas $\gamma$;
   - Começamos por criar vácuo com a câmara vazia (estudo do ambiente) e realizamos uma aquisição durante 600 segundos;
   - Verficamos a existência de um número bastante reduzido de contagens, o que era de esperar devido à ausência de fonte e ao estado de vácuo;
   - Para o estudo da eficiência para partículas gama, utilizamos uma placa de alumínio para bloquear a radiação beta.
   - Para confirmar que a placa bloqueia esta radiação, colocamos a fonte de tálio-204 com uma placa de alumínio em cima da fonte na câmara de vácuo, dado que o tálio-204 emite apenas radiação beta.
   - Criamos vácuo e ligamos o BIAS, obtendo um espetro de 600 segundos no MCA.
   - Confirmámos a existência de um número muito reduzido de contagens, o que confirma que a placa de alumínio bloqueia a radiação beta.
   - Guardamos os dados e trocamos a fonte de tálio por uma fonte de césio-137, também com uma placa de alumínio em cima.
   - Fizemos vácuo, ligamos o BIAS e obtivemos um espetro de 600 segundos no MCA.
   - Vimos um número baixo de contagens (as quais sabemos ser relativas maioritariamente a radiação gama), sem nenhum pico relevante, o que indica uma baixa eficiência gama do detetor.
5. **Estudo da fonte de Estrôncio:**  
   - Tirámos o vácuo, colocamos uma fonte de Estrôncio-99 e voltamos a fazer o processo de criação de vácuo.
   - Ligamos o BIAS e obtivemos o espetro no MCA durante 600 segundos.
   - Verificamos a existência de um único grande pico.
