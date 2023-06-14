# LogBook Relativo à Realização do Estudo da Espetroscopia Beta  

A experiência que em seguida se descreve foi realizada no dia 12 de junho de 2023 no laboratório LFE II no IST, com início às 15:50 e fim às 19:30 da tarde. O nosso grupo é o 1D e é formado pelo seguintes membros: Estêvão Gomes (ist1102650), Pedro Curvo (ist1102716), Sofia Tété (ist1102633) e Salvador Torpes (ist1102474). LogBook realizado por Sofia Tété.

1. **Calibração:**
   - Inicialmente, confirmámos que a calibração realizada na aula anterior se mantinha válida. Para tal, observámos o espetro da fonte de Césio no MCA.
   - Colocámos a fonte na câmara, ligámos o vácuo, selecionamos o modo BIAS e realizamos uma aquisição durante 120 segundos, guardando os dados num ficheiro com o nome tt_cali.asc.

2. **Estudo de uma fonte de Tálio aberta**
   - Escolhemos uma fonte de Tálio-204 aberta de outubro de 2015, que estava marcada com L12.
   - Colocámo-la dentro da câmara do detetor, ligámos o vácuo e selecionamos o modo BIAS.
   - Fizemos uma aquisição durante 600 segundos.
   - Fizemos uma análise qualitativa do espetro: conseguimos observar a distribuição característica da emissão da radiação gama - tem a forma de uma bossa na escala logarítmica no início do espetro. Não observámos mais nenhum picos, uma vez que o tálio não tem picos de conversão interna. Verificámos que, em comparação com o espetro obtido para a mesma fonte fechada, que medimos na aula anterior, o espetro obtido para a fonte aberta tem uma intensidade maior, o que é de esperar, uma vez que a fonte aberta tem menos atenuação que a fonte fechada. Logo, o espetro está distribuido por uma maior quantidade de channels (maior energia).
   - Verificámos que o numero de contagens total era maior (ROI INT = 42594 +- 206 e ROI NET = 34134 +- 483) do que no caso em que a fonte era fechada uma vez que agora não há atenuação
   - Guardámos os dados adquiridos num ficheiro com o nome ttalberto.asc;

3. **Estudo da atenuação**
   - Fizemos uma aquisição de 600 segundos para uma fonte de bismuto,na câmara com ar. 
   - Fizemos uma análise qualitativa do espetro: observámos a existência de 6 picos: o 1º relativo aos eletrões de Auger, o 2º é ruído do detetor e os 4 seguintes aparecem em pares, sendo cada par correspondente à conversão interna de duas emissões gama diferentes do bismuto.
   - Guardámos os dados adquiridos num ficheiro com o nome ttbis.asc;
   - Fizemos uma aquisição de 600 segundos para a fonte de bismuto com cartão, tendo guardado os dados no documanto ttbiscar.asc;
   - Fizemos uma outra aquisição de 600 segundos para a mesma fonte, mas desta vez com uma placa de acrílico, guardando no documento ttbisacr.asc; 

Na quarta fazer polietilenos ..