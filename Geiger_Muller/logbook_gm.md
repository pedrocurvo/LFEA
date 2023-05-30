# Logbook - Detetor Geiger-Muller #

### Trabalho realizado a 30 de maio de 2023
### Logbook por João Belas, ist1102455

## Objetivos ##

Com este trabalho experimental pretendemos estudar o detetor Geiger-Muller, um contador de partículas que é muito bom a detetar números de partículas, mas não tem resolução nenhuma em relação à sua energia.
Iremos estudar a eficiência do detetor, a relação entre a taxa de partículas detetada e a distância da fonte ao detetor e a atenuação desta taxa na presença de diferentes barreiras materiais.

## Estudo do Detetor ##

**1-** Ligámos o GMX.

**2-** Ligámos o detetor, e colocámos uma fonte de Tálio, Tl-204, demarcada com L03, na prateleira 3 (4ª prateleira).

**3-** Começámos a fazer a aquisição de contagens com uma tensão aplicada ao detetor inicial de 100V, e programada para aumentar automaticamente 25V de 2 em 2 segundos, tendo ido até a um máximo de 1200V, definido automaticamente pelo detetor. A partir dos 725V de tensão aplicada, começámos a registar contagens, o que implica que o plateau Geiger-Muller começa a partir dos 725V.

**4-** Depois de termos esta primeira aproximação grosseira, e agora que sabemos que o detetor só começa a registar contagens a partir de cerca de 700V, decidimos fazer uma aquisição mais extensiva, com um time-step de 30 segundos, a começar nos 600V, para dar alguma margem.
Mais uma vez, verificámos que o detetor só começava a registar contagens a partir dos 725V de tensão aplicada.

**5-** A sugestão da professora, repetimos o passo anterior, mas a começar nos 500V e com um time-step de 20 segundos, tal como indicado na folha do laboratório. Registámos os dados numa pen, sob o nome de ficheiro: belasgm1.asc.

**6-** Repetimos o passo **5-**, para obter um tempo total de aquisição de 40 segundos e guardámos o ficheiro com o nome belasgm2.asc.

Os dados registados encontram-se nas seguintes tabelas:

1ª aquisição de 20 segundos

Voltagens Aplicadas (V) | Contagens 1ª Aquisição | Contagens 2ª Aquisição 
:--:|:--:|:--:
500V | 0 | 0
525V | 0 | 0
550V | 0 | 0
575V | 0 | 0
600V | 0 | 0
625V | 0 | 0
650V | 0 | 0
675V | 0 | 0
700V | 0 | 0
725V | 307 | 272
750V | 360 | 378
775V | 392 | 380
800V | 445 | 430
825V | 447 | 453
850V | 457 | 444
875V | 471 | 450
900V | 457 | 485
925V | 440 | 463
950V | 446 | 455
975V | 480 | 483
1000V | 547 | 500
1025V | 489 | 514
1050V | 519 | 492
1075V | 500 | 516
1100V | 501 | 534
1125V | 515 | 519
1150V | 513 | 502
1175V | 518 | 522
1200V | 539 | 537

**7-** Após uma primeira análise destes dados no Excel, vimos que o plateau do detetor se situava desde os 800V, até sensivelmente ao máximo da aquisição, 1200V. Desta forma, decidimos usar para o resto do trabalho experimental 950V, um valor que se situa a 3/8 do patamar.

**8-** Com a tensão de aquisição escolhida, fizémos 2 aquisições de 5 segundos com a fonte virada para cima, perfazendo um total de 10 segundos, seguidas de 2 aquisições de 5 segundos com a fonte virada para baixo.
Nas aquisições com a fonte virada para cima resgistámos respetivamente, 138 e 155 contagens.
Com a fonte virada para baixo, registámos 3 e 5 contagens.

**9-** Com o recurso às fontes em meia-lua, medimos o tempo morto do detetor. As fontes em meia-lua são constituídas por 3 amostras, demarcadas com L13. As amostras 1 e 2 contém Tálio, Tl-204, e a amostra 0 não contém nenhum isótopo radioativo. Fizémos 2 aquisicões de 30 segundos seguidas, para cada uma das configurações das amostras.

**10-** Primeiramente, pusémos a amostra 1 na região direita do detetor e a amostra 0 na parte esquerda do detetor e registámos 2356 e 2498 contagens em cada uma das aquisições, , respetivamente.

**11-** Depois, colocámos a amostra 0 na região direita do detetor e a amostra 2 na região esquerda do detetor e registámos 2562 e 2579 contagens, respetivamente.

**12-** Por fim, colocámos a amostra 1 na região direita e a amostra 2 na região esquerda do detetor e registámos 4911 e 5032 contagens, respetivamente.

**13-** Para medir a radiação ambiente, fizémos duas aquisições de 30 segundos do detetor sem fonte nenhuma, e registámos 14 e 23 contagens, respetivamente.

## Estudo da eficiência do detector ##  

**1-** Para estudar a eficiência do detetor na leitura de radiações $\gamma$, colocámos a fonte de Césio, Cs-137, demarcado com L04, na prateleira 3, virada para cima, e uma chapa metálica de espessura $\phi = (1,250 \pm 0,025) mm$ na prateleira 0, de forma a bloquear a radiação $\beta$, que tem dificuldade em penetrar metal, ao contrário da radiação  $\gamma$. Fizémos 3 aquisições de 30 segundos, tendo registado 1316, 1085 e 1125 contagens, resptivamente.

**2-** Reparámos que a placa devia ser usada para o Tálio, por isso repetimos o passo anterior, mas sem a placa metálica, tendo obtido nas aquisições 7238, 7436 e 7792 contagens, resptivamente. Depois, pusémos uma placa metálica diretamente em cima da fonte, de forma a bloquear a radiação $\beta$, e fizémos também 3 aquisições tendo obtido 593, 548 e 554 contagens, respetivamente.

**3-** Para estudar a eficiência do detetor para a radiação $\beta$, pusémos a fonte de Tálio, Tl-204, com uma placa metálica imediatamente em cima da fonte, com o intuito de bloquear a radiação $\beta$ na totalidade e fizémos 3 aquisições de 30 segundos tendo obtido 24, 25 e 24 contagens, respetivamente. Estes valores estão muito próximos da radiação ambiente,, o que significa que a radiação $\beta$ foi bloqueada quase na totalidade. Depois, colocámos uma placa colimadora na prateleira 0 com $\phi=10,0mm$ de diâmetro tabelado e retirámos a placa que estava diretamente em cima da fonte de Tálio, de forma a controlar o ângulo sólido pela qual a radiação $\beta$ consegue passar e fizémos mais 3 aquisições de 30 segundos, tendo obtido 179, 190 e 177 contagens, respetivamente.

## Estudo da intensidade da radiação com a distância ##

**1-** Para estudar a variação da taxa de contagem da radiação com a distância da fonte ao detetor, medimos as partículas detetadas pela fonte de Césio, Cs-137 nas diferentes prateleiras, e com a placa colimadora usada no ponto acima para controlar o ângulo sólido da passagem da radiação $\beta$, fizémos 2 contagens de 30 segundos para cada prateleira, começando na 0 e indo até à 5. Os valores obtidos encontram-se na seguinte tabela:

Prateleira | Contagens 1ª Aquisição | Contagens 2ª Aquisição 
:--:|:--:|:--:
0 | 21049 | 21231
1 | 13210 | 13345
2 | 5462 | 5540
3 | 2841 | 2809
4 | 1809 | 1716
5 | 1304 | 1233

**2-** Como a fonte de Césio tabém emite radiação $\gamma$ e esta não é bloqueada pela placa metálica, repetimos o passo **1-** com a placa metálica diretamente em cima da fonte de Césio, de forma a que só passe a radiação $\gamma$. Assim, na análise subtrairemos um valor ao outro, filtrando o "ruído" (radiação $\gamma$), e ficando só com os valores da radiação $\beta$, com o ângulo sólido bem definido, em função da distância ao detetor.

Prateleira | Contagens 1ª Aquisição | Contagens 2ª Aquisição 
:--:|:--:|:--:
0 | 2024 | 1980
1 | 1258 | 1224
2 | 691 | 648
3 | 435 | 396
4 | 325 | 343
5 | 239 | 248

**3-**  Medimos a distância de cada prateleira ao detetor, tendo obtido os seguintes valores:

Prateleira | Distância ao detetor (m) 
:--:|:--:
0 | 0,00635
1 | 0,0127
2 | 0,019
3 | 0,0254
4 | 0,0318
5 | 0,0381

## Estudo da atenuação de partículas na matéria ##

**1-** Para estudar a atenuação na matéria da radiação detetada, colocámos a fonte de Césio na prateleira 3, com a placa colimadora usada nos passos anteriores na prateleira 0, colocámos chapas de diferentes materiais diretamente por cima da fonte, e fizémos 2 aquisições de 30 segundos para cada chapa. Os resultados obtidos encontram-se na seguinte tabela:


## Cs Tapado
Material da Chapa | Espessura $\pm 0,025$ (mm) | Contagens 1ª Aquisição | Contagens 2ª Aquisição 
:--:|:--:|:--:|:--:
Ar (sem chapa) | - | 343 | 340
Cartão | 1,000 | 356 | 341
Acrílico | 1,750 | 368 | 339
Tungsténio | 5,000 | 297 | 262
Cobre | 1,300 | 309 | 329
Aço | 2,000 | 331 | 343
Vidro | 1,750 | 362 | 330
Chumbo | 1,800 | 337 | 324
Alumínio | 1,650 | 323 | 329



**2-** Tal como no estudo  da atenuação da taxa de contagens com a distância, repetimos o processo anterior, mas colocando a chapa de alumínio entre a fonte e a outra chapa que queríamos estudar, de forma a bloquear a radiação $\beta$, e ficarmos com a atenuação da radiação $\gamma$. Para estudar a atenuação da radiação $\beta$, poderemos subtrair o sinal dos $\gamma$ ao total. Para o ar + alumínio, usámos os valores obtidos anteriormente para a chapa de alumínio e para o alumínio + alumínio usámos duas chapas de alumínio sendo a segunda da caixa das placas usadas na experiência radiação gama, demarcada com o número 7 e 81,2 (mg/cm^2) de espessura mássica, para podermos estudar a atenuação da radiação gama isoladamente no alumínio. Os valores obtidos encontram-se na seguinte tabela:

## Ta destapado

Material da Chapa + Chapa de Alumínio | Espessura $\pm 0,025$ (mm) | Contagens 1ª Aquisição | Contagens 2ª Aquisição 
:--:|:--:|:--:|:--:
Ar (sem chapa) | - | 127 | 114
Cartão | 1,000 | 38 | 30
Acrílico | 1,750 | 17 | 20
Tungsténio | 5,000 | 14 | 19
Cobre | 1,300 | 25 | 26
Aço | 2,000 | 22 | 23
Vidro | 1,750 | 21 | 21
Chumbo | 1,800 | 25 | 23
Alumínio | 1,650 | 17 | 19

**3-** Por fim, medimos os diâmetros das fontes de Tálio e Césio. O dâmetro da fonte de Tálio é $dtálio=(25,500\pm0,025)mm$ e $dcésio=(25,000\pm0,025)mm$