import os
import sys

if __name__ == '__main__':
    lista = [
        'Cesio',
        'Cobalto',
        'Fonte_Desconhecida',
        'Ruido',
        'Chumbo_Fino',
        'Chumbo_Grosso',

    ]
    directory = 'Data_Files/'
    ext1 = '.dat'
    ext2 = '_Energy.dat'
    for file in lista:
        os.system(f'python3 src/Channel_to_Energy.py {directory}{file}{ext1}')
        os.system(f'python3 src/Denoise.py {directory}{file}{ext2}')
    os.system('make bin/Analise.exe')
    os.system('bin/Analise.exe')