# Prova Prática MD

# 1. Instruções do Programa de Aquisição Multicanal (MCA)
## Inicialização do Programa
### No terminal
- Muda para a diretoria do programa:
    ```
    cd mca
    ```
- Lança o programa de aquisição:
    ```
    pca
    ```

### Aquisição
- Inicia e termina a aquisição:
<kbd>F1</kbd>
- Bloqueia e desbloqueia limpeza:
<kbd>F2</kbd> (erase fica a vermelho)
- Apaga a aquisição:
<kbd>ctrl</kbd> + <kbd>F2</kbd>
- Seleciona o tempo de aquisição:
<kbd>F3</kbd> (0 = tempo infinito)

### Visualização
- Deslocar o cursos pelos canais: <kbd>setas</kbd>
- Desloca rapidamente pelos canais: <kbd>page up</kbd> <kbd>page down</kbd> 
- Muda a escala vertical: <kbd>seta cima</kbd> <kbd>seta baixo</kbd> (LOG = escala logarítmica)

### Análise de Picos
- Marca início da ROI: <kbd>F9</kbd>
- Marca fim da ROI: <kbd>F10</kbd>
- Liga o cálculo de parâmetros do pico: <kbd>Alt</kbd> + <kbd>a</kbd> 
- Apaga a ROI: <kbd>Del</kbd> (com o cursor na ROI)


    #### Parâmetros
    - ROI Int:
    - ROI Net: 
    - Centroid:
    - FWHM:
### Gravar Dados
Os dados podem ser guardados no disco e posteriormente transferidos com recurso a uma disquete.
Quando guardados em binário é possível reabrir o espetro no programa.
Guardando em Ascii é possível reabrir o programa em casa.
- Instruções:
    - <kbd>alt</kbd> + <kbd>f</kbd>
    - Ascii File Save
    - <kbd>alt</kbd> + <kbd>q</kbd>
    - Make PCA resident
    - Meter a disquete na drive e: 
        ```
        copy <nome do ficheiro> a: 
        ```
    - Depois da luz da disquete apagar podem tirar a disquete e voltar ao programa
        ```
        exit
        ```


# 2. Osciloscópio
## Qual o significado da intensidade da luz? 
> A Intensidade da luz está relacionada com o número de eletrões que atingem as placas de fósforo do Osciloscópio. Quanto maior a corrente, maior o número de eletrões, maior a intensidade da luz.

## Amplitude do Pulse:
>   0.4V

## Caracterize Temporalmente o Pulso
> 20ms taxa temporal, exponencial negativa (ver quando o pulso passa a metade)

## Entrada Unipolar e Bipolar:
### Amplitude do Pulso:
- Unipolar: 
> 1.0V
- Bipolar:
> 0.08V
### Caracterize Temporalmente o Pulso:
- Unipolar
>20ms taxa temporal, exponencial negativa (ver quando o pulso passa a metade)
- Bipolar
> 20ms taxa temporal, exponencial negativa (ver quando o pulso passa a metade)

## Trigger do osciloscópio:
- Quando o trigger está pressionado (botão para dentro), o sinal começa a ser mostrado para valores acima da amplitude de trigger; 
- Se o trigger não estiver pressionado (botão de trigger para fora), o osciloscópio começa a mostrar o sinal;
- O osciloscópio mostra um sinal quando a barra de trigger cruza este sinal: temos de mover o botão de trigger até cruzar o sinal e é aí que o sinal aparece

## Pulser:
- ligado ao osciloscópio 
- liga-se à entrada sem pinta
- ligado ao amplificador e depois ao PC
- liga-se à entrada com pinta
- ligar o pulser no PC: abrir a gestão de dispositivos e ver qual a entrada COM# a que o pulser está ligado;
- abrir o putty  e preencher com as especificações das instruções;

## Programa de aquisição Multicanal (computador WW2)
- mudar a escala: <kbd>setas</kbd> e <kbd>enter</kbd> (em escala logaritmíca a gaussiana aparece como uma parábola invertida $e^{-x^2}$ ) 
- limpar os dados: <kbd>ctrl</kbd> + <kbd>F2</kbd>
- iniciar ou parar medição: <kbd>F1</kbd>
- centroide = média;
- largura à meia altura = $2.355\sigma$ (desvio padrão)
- para obter os dados da gaussiana associada aos dados:        
    - selecionar o início <kbd>F9</kbd>
    - selecionar o fim - <kbd>F10</kbd>
    - <kbd>alt</kbd> + <kbd>a</kbd>
- Calibração: queremos encontrar uma equivalência de valores medidos para a amplitude em volts e para o número de channels (Chn) dado pelo computador: se medirmos só um sinal simultaneamente no osciloscópio e no PC podemos dizer 
que a amplitude medida em volts no oscilóscopio corresponde ao número de channels medido no PC: esta é calibração.


# 3. Geiger-Müller e Detetor de Silício 
## Detetor de Silício
 
O detetor de silício é um detetor onde o meio a ser ionizado é um semi-condutor.
- Neste caso o detetor é um detetor de partículas alfa que possui um bomba de vácuo
- Procedimento: abrir a câmara de vácuo do detetor de silício (coiso castanho - deteta partícula alfa) -> introduzir a fonte radiativa dentro da câmara de vácuo -> fechas a câmara -> ligar a bomba de vácuo (muito barulho) -> esperar um minuto até a bomba deixar de fazer estrilho -> rodar a válvula tripla do detetor de diz vacuum para o 'vacuum' -> esperar um minuto -> comutar a válcula tripla para o 'hold' -> desligar a bomba de vácuo -> confirmar que há vácuo -> ligar o output do detetor ao osciloscópio e observar o sinal -> mudar o sinal entre bias e pulser no detetor e observar como o sinal se altera no osciloscópio
- Quando temos o bias ligado, a placa NP fica polarizada e podemos e observamos o sinal requisitado;

## Detetor Geiger-Muller
- o detetor ativo é um gás raro: deteta interações
- Partículas carregadas atravessam o gás e ionizam-no: consoante o campo elétrico existente dentro do detetor, as partículas ionizadas podem 
    ou não ter energia suficiente para ionizar outras partículas que as rodeiem
- O campo elétrico dentro do detetor existe devido a uma diferença de potencial - ligo um cabo de alta tensão ao detetor que está ligado a uma escala de alta tensão em kilovolts;
- Regimes do detetor: inicialmente só as partículas ionizadas são detetadas, mas à medida que o campo elétrico ao qual o detetor está sujeito vai aumentando (aumento da alta tensão), as partículas ionizadas detetadas aumentam linearmente até se atingir a saturação no detetor: detetam-se mais partículas à medida que o campo aumenta porque as partículas ionizadas pelas partículas carregadas que atravessam o gás têm energia suficiente para ionizar as que as rodeiam. A fonte de partículas ionizadas é uma fonte radioativa que emite eletrões; 
- Para detetar o sinal ligamos o detetor diretamente ao osciloscópio;
- Fonte de tálio: emissor Beta puro (normalmente emissores beta são também emissores gamma na desexcitação);
- O que acontece no detetor? a fonte radioativa emite eletrões -> eletrões/partículas carregadas entram no detetor gasoso -> os átomos do gás nobre que estão no detetor são ionizados -> consoante a voltagem à qual o detetor está sujeito, pode haver uma ionização parcial ou total do gás (detetor saturado ou não) -> no osciloscópio quando o detetor está saturado todos os picos negativos têm a mesma amplitude (se tiverem picos diferentes é porque ainda não está saturado) - a amplitude do sinal no osciloscópio proveniente do detetor corresponde à quantidade de partículas ionizadas no detetor;
- Plateau do detetor GM: existe um intervalo de voltagens (normalmente entre 750 e 950 Volts) no qual o aumento da tensão à qual o detetor está sujeito não provoca um aumento das partículas ionizadas - ou seja, não se observa um aumento de amplitude no sinal do osciloscópio proveniente do detetor;
- Na saturação di detetor, todas as partículas do gás estão ionizadas e o efeito da alta voltagem é fazer com que as partículas ionizadas ionizem as restantes;

## Montagem detetor GM
- em frente ao detetor Geiger-Muller colocar a fonte radioativa de tálio (moeda) num pequeno suporte
- o Geiger-Muller tem duas aberturas: numa liga-se o cabo de alta de tensão e na outra um cabo para ligar ao osciloscópio
- ligar o cabo de alta tensão (cabo vermelho) a uma das fontes de alta tensão 
- ligar o outro cabo ao ch1 do osciloscópio
- posteriormente ligar o detetor a um amplificador (caixa in/out) e o amplificador ao osciloscópio; cabo do detetor ligado 
     à abertura in e cabo ligado da abertura out ao osciloscópio ch1

## Questões GM: 
### Se utilizar o pulso sem amplificador, qual a taxa máxima para que a amplitude dos pulsos não seja alterada em mais de 3%?
> ...
### E com o uso do amplificador?
> ...

### Identifique as diferentes componentes do sistema. 
> Temos uma fonte de alta tensão, um osciloscópio, um cabo de alta tensão, um cabo de sinal, um detetor Geiger-Muller, uma fonte radioativa de tálio e um suporte para a fonte
### Identifique o Plateau e caracterize-o.
> O Plateau corresponde à zona de saturação. Para identifiar o Plateau fomos aumentando lentamente a tensão até encontrar o valor a partir do qual a amplitude do pico já não aumentava, isto é, até encontrar o valor de tensão a partir do qual o sistema fica saturado. Existe um patamar de saturação na qual a amplitude não varia, sendo que a amplitude  volta a aumentar para valores superiores ao fim do patamar. A tensão de início do patamar registada foi 690V e a tensão do fim foi 860V.

### Qual a importância deste patamar?
> Escolhemos 760V como a tensão a utilizar (aproximadamente metade do patamar). O plateau é importante porque nos permite obter a tensão que queremos utilizar nas seguinte smedições - a tensão de saturação do detetor.

### Qual a relação entre o sinal no osciloscópio e o número de contagens?
> O número de contagens corresponde ao número de vezes que a imagem pisca no osciloscópio.

### Qual o sinal que o detector regista na ausência de uma fonte? O que significa? É necessário efectuar uma correcção?
> O detetor regista a radiação ambiente, a qual provoca um erro sistemático na nossa medição, pelo que é necessário ser feita uma correção.

### Qual a incerteza na taxa de fundo numa aquisição de 60 segundos? E de 600 segundos?
> Num minuto obtivemos 35 counts e em 10 minutos obtivemos 310 counts. A origem destas contagens são os declínios radioativos pelo que sabemos que descrevem uma distribuição de Poisson, pelo que o desvio(erro da medição) é a raiz do valor médio. Pra 1 minuto o erro é aproximadamente 6 e para 10 minutos o erro é sqrt(310). Para comparar os dois erros dividimos o 2º por 10, para obter o erro por minuto.

### Como poderá utilizar as fontes para verificar que realmente o detetor satura?
> Voltámos a ver o número de counts mas agora com a fonte encostada, tendo obtido 41529 counts para 1 minuto. O ângulo sólido varia com o quadrado da distância, por isso queremos ver se o número de contagens varia do mesmo modo. Para uma fonte muito próxima os efeitos geométricos importam.


# 4. Detetor de Cintilação
## Questões




### Procedimento experimental
- Colocamos o césio perto do cristal do cintilador
- Ligamos a fonte de alta tensão ao detetor
- Ligamos o detetor ao amplificador e o amplificador ao osciloscópio 
- Em seguida, ligamos um cabo T à entrada do osciloscópio de modo a poder receber o sinal proveniente do amplificador e simultaneamente envia-lo para o computador. de modo a obter o espetro de emissão do césio todo nos 1024 canais do sistema de aquisição, colocamos o amplificar num fator de 10;
- Queremos establecer uma relação unívoca entre a energia dos eletrões no detetor e o número de canais do sistema de aquisição:

### Calibração do sistema 
Para calibrar o sistema vamos recorrer ao **_pulser_** para fazer uma regressão linear entre o número de canais e a energia do pulso incidente - assim podemos estimar qual é a energia correspondente a qualquer ponto - o valor de calibração é o pico dos raios $\gamma$ que está tabelado (usamos o tabelado para calibrar)
### Calibração com o pulser
- Medimos o numero de channels correspondentes a cinco pulses diferentes: fizemos o ajuste linear recoorrendo ao python e sabendo que o ponto de calibração é o do centróide visto anteriormente =(538,67 ch;661,657 keV);
- o numero de eletrões resultante de cada choque de fotões (com a mesma energia) no cristal segue uma distribuição de poisson - o conjunto de todos os eletrões que chocam com o cristal segue uma distribuição normal daí que facamos o ajuste de uma gaussiana aos picos de energia observados no sistema de aquisição (PC) - a incerteza da média (o erro) é a média(sigma) a dividir por raiuz de N (n de medições)
- o espetro de energia tem uma gaussiana na radiação $\gamma$;
### Identifique os parâmetros de operação do detetor.
> Os parâmetros são a alta tensão e o pré-amplificador (não vamos mexer neste último)

### Analise os espectros identificando e caracterizando as diferentes estruturas que possam estar presentes.
> Conseguimos ver um total de 3 picos. Inicialmente existe o pico mais alto de todos (o qual tem menos energia dado que está no início do eixo dos x). Este pico corresponde aos raios X emitidos pela fonte de césio. De seguida, vê-se o patamar de compton, isto é, uma parte aproximadamente reta onde também se verifica a existência de emissão de radiação $\gamma$. No meio do patamar existe um pequeno pico, associado à emissão de radiação gama. Após o patamar de compton temos o maior pico, o qual corresponde também à emissão de radiação gama (neste caso a mais energética).

### Qual a estatística que deve ser utilizada por forma a ter uma incerteza de 10% no número de contagens do pico de absorção total do Césio?
> Estamos perante uma distribuição de Poisson, pelo que a incerteza é dada por sqrt(N), onde N é o número de contagens. Queremos que a incerteza seja 10% do número de contagens, ou seja, sqrt(N)=0.1N. Logo, concluimos que N=10.
     
### Qual a estatística que deve ser utilizada por forma a ter uma incerteza de 10% na posição do centroide do pico de absorção total do Césio? 
> Utilizando o mesmo método que anteriormente, queremos $\sigma\sqrt(N)=0.1$. Logo $N=100{\sigma}^2$

### Radiação Ambiente
### O sistema regista eventos na ausência de uma fonte radioativa? 
> Sim, a radiação ambiente maioritariamente devida à existência de potássio-40 em muitos dos materiais do dia-a-dia.

### Compare a taxa de eventos com as outras aquisições.  
> Existem menos eventos do que nas outras aquisições feitas com a fonte radioativa.

### Consegue identificar alguma estrutura? Quanto tempo necessitaria para ter uma incerteza de 10% na taxa de eventos no pico de absorção total do 40K ?
> Temos que fazer extamente as mesmas contas que realizámos anteriormente, obtendo de novo N=100 e $N=100{\sigma}^2$.




## Funcionamento do detetor de cintilação
- aceleramos os eletrões com campos elétricos
- a fonte emite fotões mais ou menos energéticos - no cristal do detetor ocorre efeito fotoelétrico devido à metal coat na qual o metal está envolto e há emissão de eletrões (foteletrões) que são tanto mais energéticos consoante os fotões que lhes deram origem
- em seguida os eletrões entram no fotomultiplicador onde atravessam diversas placas sujeitas a uma diferença de potencial
- entre as placas existe um campo eleétrico que acelera os eletrões de tal modo que quando eles embatem nas placas seguintes têm energia suficiente para retirar mais eletrões
- no fim atinge o detetor e são detetatos eletrões em diferentes quantidades consoante as suas energias;


## 6. Resolução teste prático 2021:
- Meça a amplitude do pulso à saída do gerador: comparar o numero de divisões com  escala dada;
- Caracterize temporalmente o pulso à saída do pulser: dizer qual o período, qual o tempo por divisão e dizer qual a natureza do decaimento (exponencial e oscilatória)
- Medir a amplitude de dez pulsos e estimar a média e o desvio padrão (desvio padrão = sigma = sum((valor -média)^2))/N - o valor d aamplitude de cada pulso aparece no temrinal do putty em milivolts quando carregamos no enter;
-  Analise a distribuição obtida com o MCA (Alt +A) - ;
-  Estime o valor da média (média = centróide) e o desvio padrão/sigma (FWHM = 2.355*sigma). A incerteza do valor médio é sigma sobre a raiz do numero de medições - o numero de medições é dado pelo ROI NET - logo a incerteza da média é sigma sobre raíz de ROI NET;
-  Utilize o detector de cintilador e a fonte de césio -  Adquira o espectro durante o tempo necessário para ter entre 3 e 5% de incerteza no número de contagens no pico de absorção total: a emissão da fonte de césio segue uma distribuição de poisson. A incerteza do número de contagens é raíz de N; se quisermos a incerteza entre 3% e 5% então o N tem de satisfazer as seguintes equações: N^1/2 = 0.03N e N^1/2 = 0.05N. Depois se saber o valor de N. Depois de saber o N vamos fazer a medição durante o tempo suficiente para obter um número de contagens entre os valores pretendidos: temos de selecionar o pico de absorção do pulso e obter um ROI (nº medições) entre os N pretendidos;
-  Adquira o espectro durante o tempo necessário para ter entre 3 e 5% de incerteza no valor médio do pico de absorção total: a incerteza do valor médio é sigma sobre raíz de N: obtemos sigma com FWHM = 2.355*sigma onde FWHM é o da alínea anterior. Para obter o N de contagens a fazer de modo a respeitar a incerteza temos de resolver a equação 0.03 < sigma/(N^1/2) < 0.05. Mais uma vez vamos fazer uma aquisição no MCA cujo ROI esteja entre os valores pedidos quando selecionamos o pico de absorção total. O ROI dá o número de contagens no espaço selecionado do espetro;
-  No detector Geiger Müeller foi registado o seguinte gráfico e ajustada uma recta: N = 1.4V - 290. Definiu-se a tensão de operação em 825 V. Qual o erro sistemático se regular a tensão para 800 V? Calcular o N para 825 e para 800 e ver a diferença. Esta reta de ajuste reflete o plateau do detetor de Geiger Muller.
-  Última pergunta: média é o valor do meio e sigma é largura a meia altura a dividir por 2.355.
-  ROI INT é om ruído e o ROI NET é com ruído;