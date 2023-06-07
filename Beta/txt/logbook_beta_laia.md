# Logbook - Radiação Beta #

### Trabalho realizado a 6 de Junho 2023
### Logbook por Nuno Gandum, ist1102741

## Objetivos ##
Determinar o limite cinemático para uma fonte de Tálio. Estudar o espetro beta de uma fonte de Bismuto. Estudar algumas características do detetor. 


**_____________________________________________________________________________________**

**1-** Começamos por pedir ao professor as fontes de radiação, sendo estas uma fonte de Cáseio (Cs-137), marcada com L07, uma fonte de Tálio (Tl-204), marcada com L06, e uma fonte de Bismuto (Bi-207), marcada com L14.

**2-** Ligámos a bomba para que esta aqueça, e, enquanto isso, ligámos o osciloscópio, à saída lin amp out, e o MCA para prontificar tudo para adquirir dados.

**3-** Colocámos a fonte de Césio na prateleira 3 e ligámos o vácuo no modo _Vent_ durante 1 minuto. Depois mudámos para o modo Pump e deixámos a câmara fazer vácuo durante 2 minutos. Colocámos o espéctometro no modo _Hold_ e desligámos a bomba, e, de seguida, ligámos o BIAS.

**4-** Adquirimos os dados durante 10 minutos e guardámos os dados num ficheiro com o nome belas6001.asc .

**5-** Para tentar complementar as aquisições do MCA, vimos o sinal no osciloscópio e adquirimos a sua amplitude [Amp = (1.00 +- 0.05)V ].

**6-** Retirámos alguns dados do pico de conversão de interna. 
[Centroid- 115.35 Chn; FwHm = 7.18 Chn; ROI NET = 5080 +- 186; ROI INT = 13970 +- 118]

Enquanto obtinhamos estes dados, fizemos uma análise qualitativa do espetro do Césio e reparámos que existia um joelho à direita do pico do eletrão de conversão. Este fenómeno acontece quando um eletrão ejetado está num nível de energia mais elevada no átomo.


**7-** Retirámos a fonte e fizemos novamente vácuo, pelo processo acima referido.

**8-** Mudámos do Bias para o Pulser/Marker e procedemos ao processo de calibração.

**9-** De forma a calibrar os dados realizámos aquisições de 1 minuto em diferentes energias no pulser de forma a posteriormente analisar e perceber qual a energia para que o pico de conversão interna aparece. Como não era possível obter o Centroid em cada uma dos diferentes valores do pulser, recolhemos as contagens por cada canal para proceder ao calculo do centroid manualmente e , após esse processo, realizar a calibração.

<table><tr><th colspan="1" valign="bottom">Valor no pulser</th><th colspan="1" valign="bottom">Chn</th><th colspan="1" valign="bottom">Count</th><th colspan="1">média</th></tr>
<tr><td colspan="1" rowspan="7">0,2</td><td colspan="1" valign="bottom">38</td><td colspan="1" valign="bottom">1</td><td colspan="1" rowspan="7">42,20261171</td></tr>
<tr><td colspan="1" valign="bottom">39</td><td colspan="1" valign="bottom">1</td></tr>
<tr><td colspan="1" valign="bottom">40</td><td colspan="1" valign="bottom">7</td></tr>
<tr><td colspan="1" valign="bottom">41</td><td colspan="1" valign="bottom">531</td></tr>
<tr><td colspan="1" valign="bottom">42</td><td colspan="1" valign="bottom">2864</td></tr>
<tr><td colspan="1" valign="bottom">43</td><td colspan="1" valign="bottom">1449</td></tr>
<tr><td colspan="1" valign="bottom">44</td><td colspan="1" valign="bottom">48</td></tr>
<tr><td colspan="1" rowspan="5">0,3</td><td colspan="1" valign="bottom">62</td><td colspan="1" valign="bottom">117</td><td colspan="1" rowspan="5">63,64741889</td></tr>
<tr><td colspan="1" valign="bottom">63</td><td colspan="1" valign="bottom">1840</td></tr>
<tr><td colspan="1" valign="bottom">64</td><td colspan="1" valign="bottom">2601</td></tr>
<tr><td colspan="1" valign="bottom">65</td><td colspan="1" valign="bottom">340</td></tr>
<tr><td colspan="1" valign="bottom">66</td><td colspan="1" valign="bottom">3</td></tr>
<tr><td colspan="1" rowspan="6">0,4</td><td colspan="1" valign="bottom">85</td><td colspan="1" valign="bottom">1</td><td colspan="1" rowspan="6">87,47309417</td></tr>
<tr><td colspan="1" valign="bottom">86</td><td colspan="1" valign="bottom">242</td></tr>
<tr><td colspan="1" valign="bottom">87</td><td colspan="1" valign="bottom">2278</td></tr>
<tr><td colspan="1" valign="bottom">88</td><td colspan="1" valign="bottom">2206</td></tr>
<tr><td colspan="1" valign="bottom">89</td><td colspan="1" valign="bottom">178</td></tr>
<tr><td colspan="1" valign="bottom">90</td><td colspan="1" valign="bottom">1</td></tr>
<tr><td colspan="1" rowspan="5">0,5</td><td colspan="1" valign="bottom">107</td><td colspan="1" valign="bottom">50</td><td colspan="1" rowspan="5">108,8338776</td></tr>
<tr><td colspan="1" valign="bottom">108</td><td colspan="1" valign="bottom">1335</td></tr>
<tr><td colspan="1" valign="bottom">109</td><td colspan="1" valign="bottom">2909</td></tr>
<tr><td colspan="1" valign="bottom">110</td><td colspan="1" valign="bottom">591</td></tr>
<tr><td colspan="1" valign="bottom">111</td><td colspan="1" valign="bottom">15</td></tr>
<tr><td colspan="1" rowspan="6">0,54</td><td colspan="1" valign="bottom">117</td><td colspan="1" valign="bottom">3</td><td colspan="1" rowspan="6">119,412226</td></tr>
<tr><td colspan="1" valign="bottom">118</td><td colspan="1" valign="bottom">266</td></tr>
<tr><td colspan="1" valign="bottom">119</td><td colspan="1" valign="bottom">2520</td></tr>
<tr><td colspan="1" valign="bottom">120</td><td colspan="1" valign="bottom">2047</td></tr>
<tr><td colspan="1" valign="bottom">121</td><td colspan="1" valign="bottom">136</td></tr>
<tr><td colspan="1" valign="bottom">122</td><td colspan="1" valign="bottom">1</td></tr>
<tr><td colspan="1" rowspan="5">0,6</td><td colspan="1" valign="bottom">129</td><td colspan="1" valign="bottom">14</td><td colspan="1" rowspan="5">131,0152905</td></tr>
<tr><td colspan="1" valign="bottom">130</td><td colspan="1" valign="bottom">861</td></tr>
<tr><td colspan="1" valign="bottom">131</td><td colspan="1" valign="bottom">3090</td></tr>
<tr><td colspan="1" valign="bottom">132</td><td colspan="1" valign="bottom">916</td></tr>
<tr><td colspan="1" valign="bottom">133</td><td colspan="1" valign="bottom">24</td></tr>
<tr><td colspan="1" rowspan="5">0,7</td><td colspan="1" valign="bottom">153</td><td colspan="1" valign="bottom">74</td><td colspan="1" rowspan="5">154,7759674</td></tr>
<tr><td colspan="1" valign="bottom">154</td><td colspan="1" valign="bottom">1453</td></tr>
<tr><td colspan="1" valign="bottom">155</td><td colspan="1" valign="bottom">2887</td></tr>
<tr><td colspan="1" valign="bottom">156</td><td colspan="1" valign="bottom">491</td></tr>
<tr><td colspan="1" valign="bottom">157</td><td colspan="1" valign="bottom">5</td></tr>
</table>

**10-** Metemos a fonte de Tálio na prateleira 3 e fizemos novamente vácuo com o mesmo processo. Colocámos o espectómetro no Bias.

**11-** Adquirimos o espetro do Tálio durante 600 segundos e gravámos os dados como belas_tl.asc.

**12-** Após conversa com o professor, reparámos que o número de contagens era reduzido então resolvemos fazer uma nova aquisição do espetro do Tálio durante 600 segundos. Gravámos os dados num ficheiro como belas_tl2.asc .

**13-** Trocámos a fonte de Tálio pela fonte de Bismuto e fizemos novamente vácuo, de acordo com o processo descrito inicialmente.

**14-** Adquirimos o espetro do Bismuto durante 600 segundos e gravámos os dados num ficheiro com o nome belas_Bi1.asc. Registámos na seguinte tabela os valores do Centroid, FwHm e ROI NET para os picos possíveis e os valores de Contagens por Canal quando não era possível obter os valores anteriores (os valores de Centroid e FwHm não conseguimos  obter porque o MCA não referia estes valores e eram muitos canais para fazer manualmente, contudo quando efetuarmos a análise obteremos estes valores).

<table><tr><th colspan="1" valign="bottom">Pico</th><th colspan="1" valign="bottom">Centroid [Chn]</th><th colspan="1" valign="bottom">FwHM [Chn]</th><th colspan="1" valign="bottom">ROI NET</th><th colspan="1" valign="bottom">Chn</th><th colspan="1" valign="bottom">Counts</th></tr>
<tr><td colspan="1" valign="bottom">1</td><td colspan="1" valign="bottom"> - </td><td colspan="1" valign="bottom"> - </td><td colspan="1" valign="bottom">9553 ± 142</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td></tr>
<tr><td colspan="1" valign="bottom">2</td><td colspan="1" valign="bottom">35.77</td><td colspan="1" valign="bottom">12.89</td><td colspan="1" valign="bottom">5665 ± 235</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td></tr>
<tr><td colspan="1" valign="bottom">3</td><td colspan="1" valign="bottom">103.87</td><td colspan="1" valign="bottom">1.79</td><td colspan="1" valign="bottom">2066 ± 87</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td></tr>
<tr><td colspan="1" rowspan="9">4</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">117</td><td colspan="1" valign="bottom">143</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">118</td><td colspan="1" valign="bottom">136</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">119</td><td colspan="1" valign="bottom">267</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">120</td><td colspan="1" valign="bottom">315</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">121</td><td colspan="1" valign="bottom">198</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">122</td><td colspan="1" valign="bottom">160</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">123</td><td colspan="1" valign="bottom">152</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">124</td><td colspan="1" valign="bottom">131</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">125</td><td colspan="1" valign="bottom">103</td></tr>
<tr><td colspan="1" rowspan="4">5</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">209</td><td colspan="1" valign="bottom">39</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">210</td><td colspan="1" valign="bottom">109</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">211</td><td colspan="1" valign="bottom">325</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">212</td><td colspan="1" valign="bottom">182</td></tr>
<tr><td colspan="1" rowspan="3">6</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">226</td><td colspan="1" valign="bottom">27</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">227</td><td colspan="1" valign="bottom">62</td></tr>
<tr><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">-</td><td colspan="1" valign="bottom">228</td><td colspan="1" valign="bottom">31</td></tr>
</table>



**15-** Em conversa com o professor chegámos à conclusão de várias coisas acerca do espetro do Bismuto. Percebemos que o 1º pico resulta da libertação de eletrões de Auger devido à excitação do átomo em si e não do núcleo. A largura considerável do pico advém do facto de estes eletrões serem resultantes de eletrões de várias camadas e como tal a energia que possuiam ao ser libertados seria ligeiramente diferente, aumentando a largura do pico. Percebemos que o 2º pico (achatado e largo) resulta de eletrões que têm energia superior àquela que faz com que sejam parados pela placa de silicio. Como tal, não são parados mas depositam pequenas quantidades de energia do silício pelo que o detetor asume que são particulas beta com energia menor. Quanto aos ultimos 4 picos finos, verificámos que vêm aos pares, pelo que percebemos que o decaimento do Bismuto ocorre em duas fases. O Bismuto inicial decai para um núcleo instável uma vez libertando um eletrão, contudo como o núcleo ainda permanece instável ocorre um novo decaimento para um núcleo estável libertando um novo eletrão. Assim, percebemos que as duas estruturas existentes são ambas os diversos picos de energia para cada um dos decaimentos. É de ressalvar ainda que os restantes picos não são possíveis de visualizar devido à pouca resolução do MCA.

**16-** Adquirimos, novamente, dados do espetro do Bismuto durante 600 segundos e gravámos os dados num ficheiro com o nome laiabi3.asc. 

**17-** Retirámos a fonte de Bismuto e adquirimos a radiação existente no fundo (sem fonte), guardando os dados como laia_amb.asc. 
Verificámos que as contagens existentes eram quase zero, o que faz sentido tendo em conta que dentro do espectómetro se encontrava apenas vácuo.

**18-** Colocámos uma placa de alumínio sobre a fonte de Césio e fizémos vácuo de acordo com o procedimento explicado no início. Guardámos os dados e gravámos o ficheiro com o nome laia_cs.asc .

**19-** Copiámos todos os dados adquiridos para a disquete para posterior analise. 




