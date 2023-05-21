# Instruções do Programa de Aquisição Multicanal
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
