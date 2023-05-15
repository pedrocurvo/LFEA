2. Visualização de Sinais no Osciloscópio

Amplitude do Pulse:
    0.4V
Caracterize Temporalmente o Pulso:
    20ms taxa temporal, exponencial negativa (ver quando o pulso passa a metade)

Entrada Unipolar e Bipolar:
    Amplitude do Pulso:
        Unipolar: 1.0V
        Bipolar: 0.08V
    Caracterize Temporalmente o Pulso:
        Unipolar: 20ms taxa temporal, exponencial negativa (ver quando o pulso passa a metade)
        Bipolar: 20ms taxa temporal, exponencial negativa (ver quando o pulso passa a metade)

Trigger do osciloscópio:
    quando o trigger está pressionado (botão para dentro), o sinal começa a ser mostrado para valores acima da amplitude de trigger; 
    Se o trigger não estiver pressionado (botão de trigger para fora), o osciloscópio começa a mostrar o sinal;
    o osciloscópio mostra um sinal quando a barra de trigger cruza este sinal: temos de mover o botão de trigger até cruzar o sinal e 
    é aí que o sinal aparece

Pulser:
    - ligado ao osciloscópio - liga-se à entrada sem pinta
    - ligado ao amplificador e depois ao PC - liga-se à entrada com pinta
    - ligar o pulser no PC: abrir a gestão de dispositivos e ver qual a entrada COM# a que o pulser está ligado; abrir o putty
    e preencher com as especificações das instruções;

Program de aquisição Multicanal (computador 2WW)
    - mudar a escala: setas e enter (em escala logaritmíca a gaussiana aparece como uma parábola invertida e^(-x^2))
    - limpar os dados: ctrl + F2
    - iniciar ou parar medição: F1
    - centroide = media;
    - largura à meia altura = 2.355 x desvio padrão 
    - para obter os dados da gaussiana associada aos dados: selecionar o início - F9 - selecionar o fim - F10 - alt + A
    - Calibração: queremos encontrar uma equivalência de valores medidos para a amplitude em volts e para o número de 
    channels (Chn) dado pelo computador: se medirmos só um sinal simultaneamente no osciloscópio e no PC podemos dizer 
    que a amplitude medida em volts no oscilóscopio corresponde ao número de channels medido no PC: esta é 
    calibração.

Detetor de Geiger:
    - o detetor ativo é um gás raro: deteta interações
    - partículas carregadas atravessam o gás e ionizam-no: consoante o campo elétrico, as partículas ionizadas podem 
    ou não ter energia suficiente para ionizar outras partículas que as rodeiem
    - aplico um campo elétrico aplicando uma diferença de potencial - ligo um cabo de alta tensão ao
    detetor que está ligada a uma escala de alta tensão em kilovolts;
    - Regimes do detetor: inicialmente só as partículas ionizadas são detetadas, mas à medida que o campo elétrico 
    ao qual o detetor está sujeito vai aumentando, as partículas ionizadas detetadas aumentam linearmente até
    se atingir a saturação no detetor: detetam-se mais partículas à medida que o campo aumenta porque as partículas 
    ionizadas pelas partículas carregadas que atravessam o gás têm energia suficiente para ionizar as que as 
    rodeiam. A fonte de partículas ionizadas é uma fonte radioativa que emite eletrões 
    - para detetar o sinal ligamos o detetor diretamente ao osciloscópio
    - fonte de tálio: emissor Beta puro (normalmente emissores ebta são também emissores gamma na desexcitação)
    - fonte radioativa emite eletrões -> eletrões/partículas carregadas entram no detetor gasoso -> os átomos do gás nobre que estão no 
     detetor são ionizados -> consoante a voltagem do detetor pode haver uma ionização parcial ou total (saturado) -> no osciloscópio
     quando o detetor está saturado todos os picos negativos têm a mesma amplitude (se tiverem picos diferentes é porque ainda não está saturado)
    - na saturação todas as partículas do gás estão ionizadas e o efeito da alta voltagem é fazer com que as partículas ionizadas ionizem as restantes

    Montagem:
    - em frente ao detetor Geiger-Muller colocar a fonte radioativa de tálio (moeda) num pequeno suporte
    - o Geiger-Muller tem duas aberturas: numa liga-se o cabo de alta de tensão e na outra um cabo para ligar ao osciloscópio
    - ligar o cabo de alta tensão (cabo vermelho) a uma das fontes de alta tensão 
    - ligar o outro cabo ao ch1 do osciloscópio
    - posteriormente ligar o detetor a um amplificador (caixa in/out) e o amplificador ao osciloscópio; cabo do detetor ligado 
     à abertura in e cabo ligado da abertura out ao osciloscópio ch1

Questões: 
    Se utilizar o pulso sem amplificador, qual a taxa máxima para que a amplitude
    dos pulsos não seja alterada em mais de 3%?
    
    E com o uso do amplificador?
        -

    Qual o significado da intensidade da luz? 
        A Intensidade da luz está relacionada com o número de eletrões que atingem
        a camada de fósforo do Osciloscópio. Quanto maior a corrente, maior o número de eletrões, 
        maior a intensidade da luz.

Questões (Geiger-Muller):
    -Identifique as diferentes componentes do sistema. 
      Temos uma fonte de alta tensão, um osciloscópio, um cabo de alta tensão, um cabo de sinal, um detetor Geiger-Muller, 
      uma fonte radioativa de tálio e um suporte para a fonte
    - Identifique o Plateau e caracterize-o.
     O Plateau corresponde à zona de saturação. Para identifiar o Plateau fomos aumentando lentamente a tensão até encontrar
     o valor a partir do qual a amplitude do pico já não aumentava, isto é, até encontrar o valor de tensão a partir do qual
     o sistema fica saturado. Existe um patamar de saturação na qual a amplitude não varia, sendo que a amplitude  volta a aumentar para valores
     superiores ao fim do patamar. A tensão de início do patamar registada foi 690V e a tensão do fim foi 860V.
    - Qual a importância deste patamar?
    
    Escolhemos 760V como a tensão a utilizar (aproximadamente metade do patamar). 

    -Qual a relação entre o sinal no osciloscópio e o número de contagens?
     O número de contagens corresponde ao número de vezes que a imagem pisca no osciloscópio.
    - Qual o sinal que o detector regista na ausência de uma fonte? O que significa? É necessário efectuar uma correcção?
    O detetor regista a radiação ambiente, a qual provoca um erro sistemático na nossa medição, pelo 
    que é necessário ser feita uma correção.
    - Qual a incerteza na taxa de fundo numa aquisição de 60 segundos? E de 600 segundos?
    Num minuto obtivemos 35 counts e em 10 minutos obtivemos 310 counts. A origem destas contagens são os declínios radioativos pelo
    que sabemos que descrevem uma distribuição de Poisson, pelo que o desvio(erro da medição) é a raiz do valor médio.
    Pra 1 minuto o erro é aproximadamente 6 e para 10 minutos o erro é sqrt(310). Para comparar os dois erros dividimos o 2º por 10, 
    para obter o erro por minuto.
    - Como poderá utilizar as fontes para verificar que realmente o detetor satura?
    Voltámos a ver o número de counts mas agora com a fonte encostada, tendo obtido 41529 counts para 1 minuto. 
    O ângulo sólido varia com o quadrado da distância, por isso queremos ver se o número de contagens varia do mesmo modo. 
    Para uma fonte muito próxima os efeitos geométricos importam.