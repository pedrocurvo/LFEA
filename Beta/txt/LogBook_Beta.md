# LogBook Relativo à Realização do Estudo da Espetroscopia Beta  

A experiência que em seguida se descreve foi realizada no dia 7 de junho de 2023 no laboratório LFE II no IST, com início às 11:30 da manhã e fim às 15:00. O nosso grupo é o 1D e é formado pelo seguintes membros: Estêvão Gomes (ist1102650), Pedro Curvo (ist1102716), Sofia Tété (ist1102633) e Salvador Torpes (ist1102474). LogBook realizado por Pedro Curvo.

1. **Calibração:**
   - Objetivo: calibrar o sistema recorrendo a um pulser que emite pulsos de energia 620 keV, o que corresponde ao pico de conversão interna do Cs-137, elemento cujo espetro também vamos estudar;
   - Começamos por ligar o computador bem como abrir o programa de aquisição de dados MCA;
   - De seguida, pedimos ao professor as fontes radioativas necessárias para a realização da experiência, sendo elas: o Césio Cs-137 (marcado com L07), o Tálio Tl-204 (marcado com L06) e o Bismuto Bi-207 (marcado com L14);
   - Ligamos o detetor ao osciloscópio (saída lamp out) e ao MCA;
   - Colocamos a fonte de Cs-137 dentro do detetor e fechamos a câmara. Ligamos a bomba de vácuo e selecionamos o modo Vent durante um minuto. Mudamos o dial para o modo pump e esperámos que o vácuo se establecesse durante 2 minutos;
   - Por fim, selecionamos o modo Hold e desligamos a bomba de vácuo;
   - Ligamos o BIAS (de modo a ativar o campo elétrico do detetor de silício) e iniciamos a aquisição de dados no MCA durante 10 minutos com o objetivo de obter o espetro de energia do Cs-137;
   - Enquantos os dados eram adquiridos, observamos o sinal no osciloscópio e medimos a sua amplitude, obtendo o seguinte valor:
   $$\text{A}=\pm$$
   - Durante a aquisição, aproveitamos também para fazer uma análise qualitativa do sinal: conseguimos, no espetro do Cs-137, observar .... !!!
   - No fim da aquisição, utilizamos o MCA para retirar dados de ajuste do pico de energia do Cs-137 correspondente à energia libertada na transição nuclear e à de conversão interna (acho que o de conversao interna nao se ve por isso deve ser o outro), obtendo os seguintes valores:

    Picos Energéticos no espetro do Cs-137  | ROI Int  | ROI Net | Centroid (Chn) | FWHM (Chn) | Tempo de Aquisição (s) |
    |:---------:|:---:|:---:|:---:|:--:|:----:|
    ||  ±  |  ±  |  ±  |  |600|
    ||  ±  |  ±  |  ±  |  |600|

   - Guardamos os dados do espetro obtido no MCA para posterior análise;
   - Retiramos o vácuo da câmara e retiramos a fonte de Cs-137 do detetor;
   - Voltamos a colocar a câmara em vácuo com o BIAS desligado mas desta vez sem nenhuma fonte radioativa dentro;
   - Ligamos o Pulser e realizamos aquisições de dados para diferentes valores de energia dos pulsos emitidos pelo Pulser de modo a mais tarde podemos construir uma reta de ajuste para a calibação. Realizamos cada aquisição durante 1 minuto e obtivemos os seguintes resultados:

    Energia do Pulser | ROI Int  | ROI Net | Centroid (Chn) | FWHM (Chn) | Tempo de Aquisição (s) |
    |:---------:|:---:|:---:|:---:|:--:|:----:|
    |   |  ±  |  ±  |  ±  |  ||

   - Desligamos o vácuo;
2. **Limite Cinemático:**  
   - Objetivo: determinar a energia máxima que um eletrão resultante do decaimento $\beta$- do Tl-204 pode ter;
   - Colocamos a fonte de tálio dentro do detetor e fechamos a câmara;
   - Repetimos o processo de colocar vácuo na câmara;
   - Ligamos o BIAS e iniciamos a aquisição de dados no MCA durante 600 segundos com o objetivo de obter o espetro de energia do Tl-204;
   - Guardamos os dados do espetro obtido no MCA para posterior análise;
   - Retirámos o vácuo e retiramos a fonte de tálio do detetor;
3. **Estudo da fonte de Bismuto:**  
   - Objetivo: estudar o espetro de energia do Bi-207;
   - Colocamos a fonte de bismuto dentro do detetor e fechamos a câmara;
   - Repetimos o processo de colocar vácuo na câmara;
   - Ligamos o BIAS e iniciamos a aquisição de dados no MCA durante 600 segundos com o objetivo de obter o espetro de energia do Bi-207;
   - Após a aquisição, fizemos uma análise qualitativa do espetro obtido para o Bi-207: !!!
   - Para os picos do espetro para os quais foi possível, retiramos os dados de ajuste do MCA, obtendo os seguintes valores:

   Picos Energéticos no espetro do Bi-207  | ROI Int  | ROI Net | Centroid (Chn) | FWHM (Chn) | Tempo de Aquisição (s) |
   |:---------:|:---:|:---:|:---:|:--:|:----:|
   ||  ±  |  ±  |  ±  |  |600|
   ||  ±  |  ±  |  ±  |  |600|

   - Guardamos os dados do espetro obtido no MCA para posterior análise;
   - Repetimos a aquisição de dados do espetro do Bi-207 durante 600 segundos e voltamos a guardar os dados para posterior análise;
   - Retirámos o vácuo e retiramos a fonte de bismuto do detetor;
4. **Estudo do Detetor:**  
   - Objetivo: estudar o efeito do ambiente, as resoluções de energia e a eficiência do detetor para partículas $\gamma$;
   - Começamos por criar vácuo com a câmara vazia (estudo do ambiente) e realizamos uma aquisição durante...
