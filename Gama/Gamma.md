# Radição Gamma

1. Objetivo:
   - Medição da radiação gamma proveniente de diferentes fontes.
   - O objectivo deste trabalho é o estudo da interacção da radiação com a matéria, através dos processos fotoeléctrico, de Compton e de produção de pares, bem como das propriedades dos detectores de cintilação. Usa-se um espectrómetro simples, formado por uma fonte emissora de raios $\gamma$ e um detector de iodeto de sódio activado por tálio, NaI(Tl), com fotomultiplicador acoplado, ao qual se segue a cadeia electrónica composta por gerador de alta tensão (regulado de acordo com o PMT), pré-amplificador e amplificador de tensão, e analisador multicanal (este inserido em PC com software de aquisição de dados)

2. Estudo de espectros de fontes conhecidas e calibração:
   - Estudar o espetro de energia do césio e do cobalto: colocar as fontes em frente ao cintilador e observar o espetro no MCA (tirar o centróide para o césio e par ao cobalto). Para cada uma das fontes, retirar o centróide dos dois picos de emissão, do pico de back scattering no plateau do espetro e do joelho de compton no final do plateau (medir quatro centroides por cada fonte radioativa). Obter os valores durante dois minutos para cada fonte;
   - Calibrar os valores de channels dos centroides obtidos através dos valores tabelados para as energias dos raios gamma e dos raios X (raios X são o pico inicial) do césio e do cobalto. Realizar a calibração com uma egressão linear. Comparar os valores obtidos com para a energia dos picos de radiação, backscattering e joelho de compton das duas fontes com os valores tabelados; O objetivo da calibração é passar de channels para energia: fazemos um fit da energia em função de channels E(chn) = a*chn + b;
  
3. Identificação da fonte desconhecida:
   - A fonte desconhecida é sorteada e realizamos a aquisição do espetro de energia da fonte no MCA. Retirar os centroides de todos os picos de energia do espetro obtido: note-se que pode ser necessário aproximar no MCA o espetro para encontrar picos mais pequenos (mas que também existem);
   - Usar a calibração que já tinhamos para obter a energia de cada pico;
   - Comparar com espetros conhecidos para descobrir a fonte desocnhecida - perguntar ao chatGPT;
  
4. Identificação de fontes de radioactividade ambiente
   - Realizar uma medição para o cintilador sem nenhuma fonte radioativa e obter o centroide da emissão da radiação de fundo (ruído);
   - Colocar as fontes radioativas do lado do detetor que não deteta e obter um espetro de energia durante 20 minutos;
   - Obter os centróides dos picos de ruído que existam e comparar com espetros conhecidos para saber quais as fontes radioativas no ambiente;
   - Ao fazer os espetros de qualquer fonte, temos de subtrair sempre o espetro do ambiente: temos de fazer todos os gráficos dividindo pela taxa temporal de aquisição de cada espetro para as intensidades de energia estarem todas na mesma escala: o que interessa é a taxa temporal de emissão de energia;
  
5. Atenuação da radiação gama na matéria:
   - Escolher duas combinações das placas de chumbo disponíveis - uma combinação de baixa espessura e outra d ealta espessura;
   - Colocar as placas de chumbo entre o detetor e a fonte radiotiva (usar a do césio porque é mais estável);
   - Obter o espetro de emissão da fonte com a atenuação do chumbo: voltar a registar dos centróides de todos os picos do espetro;

6. Estudo das Características do Detetor:
   - Ainda por fazer

7. NOTAS úteis:
   - Escrever os valores das energias dos diferentes picos de cada espetro indicando qual a sua incerteza. Neste caso, como cada pico corresponde aos centróides medidos em chn que depois têm de ser passadas para valores de energia; incerteza do centroide em chn = FWHM / (2.355 * $\sqrt(ROI NET)$)
   - Tabela tipo para a obtenção de espetros:
  
|           Tabela com o registo de dados relativos ao espetro de emissão de          | Valor | Valor Calibrado |
|:---------------------------:|:-----:|:---------------:|
|             FWHM            |  $\pm$     |                 |
|           ROI INT           |       $\pm$ |                 |
|           ROI NET           |   $\pm$    |                 |
|   Centróide BackScattering  |   $\pm$    |                 |
| Centróide Joelho de Compton |   $\pm$    |                 |
|       Centróide Pico 1      |   $\pm$    |                 |
|       Centróide Pico 2      |   $\pm$    |                 |
|       Centróide Pico 3      |   $\pm$    |                 |