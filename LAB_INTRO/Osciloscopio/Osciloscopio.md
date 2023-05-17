# Visualização de Sinais no Osciloscópio

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
