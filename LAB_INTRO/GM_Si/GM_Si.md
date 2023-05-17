# Introdução ao Detetor de Silício e Geiger-Muller

## Detetor de Silício
 
O detetor de silício é um detetor onde o meio a ser ionizado é um semi-condutor.
- neste caso o detetor é um detetor de partículas alfa que possui um bomba de vácuo
- Procedimento: abrir a câmara de vácuo do detetor de silício (coiso castanho - deteta partícula alfa) -> introduzir a fonte radiativa dentro da câmara de vácuo -> fechas a câmara -> ligar a bomba de vácuo (muito barulho) -> esperar um minuto até a bomba deixar de fazer estrilho -> rodar a válvula tripla do detetor de diz vacuum para o 'vacuum' -> esperar um minuto -> comutar a válcula tripla para o 'hold' -> desligar a bomba de vácuo -> confirmar que há vácuo -> ligar o output do detetor ao osciloscópio e observar o sinal -> mudar o sinal entre bias e pulser no detetor e observar como o sinal se altera no osciloscópio

- 
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

## Questões: 
### Se utilizar o pulso sem amplificador, qual a taxa máxima para que a amplitude dos pulsos não seja alterada em mais de 3%?
> ...
### E com o uso do amplificador?
> ...

### Qual o significado da intensidade da luz? 
> A Intensidade da luz está relacionada com o número de eletrões que atingem as placas de fósforo do Osciloscópio. Quanto maior a corrente, maior o número de eletrões, maior a intensidade da luz.

### Identifique as diferentes componentes do sistema. 
> Temos uma fonte de alta tensão, um osciloscópio, um cabo de alta tensão, um cabo de sinal, um detetor Geiger-Muller, 
      uma fonte radioativa de tálio e um suporte para a fonte
### Identifique o Plateau e caracterize-o.
> O Plateau corresponde à zona de saturação. Para identifiar o Plateau fomos aumentando lentamente a tensão até encontrar o valor a partir do qual a amplitude do pico já não aumentava, isto é, até encontrar o valor de tensão a partir do qual o sistema fica saturado. Existe um patamar de saturação na qual a amplitude não varia, sendo que a amplitude  volta a aumentar para valores superiores ao fim do patamar. A tensão de início do patamar registada foi 690V e a tensão do fim foi 860V.

### Qual a importância deste patamar?
> Escolhemos 760V como a tensão a utilizar (aproximadamente metade do patamar). 

### Qual a relação entre o sinal no osciloscópio e o número de contagens?
> O número de contagens corresponde ao número de vezes que a imagem pisca no osciloscópio.

### Qual o sinal que o detector regista na ausência de uma fonte? O que significa? É necessário efectuar uma correcção?
> O detetor regista a radiação ambiente, a qual provoca um erro sistemático na nossa medição, pelo que é necessário ser feita uma correção.

### Qual a incerteza na taxa de fundo numa aquisição de 60 segundos? E de 600 segundos?
> Num minuto obtivemos 35 counts e em 10 minutos obtivemos 310 counts. A origem destas contagens são os declínios radioativos pelo que sabemos que descrevem uma distribuição de Poisson, pelo que o desvio(erro da medição) é a raiz do valor médio. Pra 1 minuto o erro é aproximadamente 6 e para 10 minutos o erro é sqrt(310). Para comparar os dois erros dividimos o 2º por 10, para obter o erro por minuto.

### Como poderá utilizar as fontes para verificar que realmente o detetor satura?
> Voltámos a ver o número de counts mas agora com a fonte encostada, tendo obtido 41529 counts para 1 minuto. O ângulo sólido varia com o quadrado da distância, por isso queremos ver se o número de contagens varia do mesmo modo. Para uma fonte muito próxima os efeitos geométricos importam.