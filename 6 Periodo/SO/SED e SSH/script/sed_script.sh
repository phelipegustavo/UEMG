#!/bin/bash

ARQUIVO=$1
echo $ARQUIVO

if [[ ! -e $ARQUIVO || -z $1 ]]
then
    echo "Informe um arquivo"
    exit
fi

ler_termos(){
    echo "Informe o termo a ser substituido: "
    read termo
    echo "Informe o termo substituto: "
    read subs
    echo
}

ler_intervalo(){
    echo "Informe a linha inicial: "
    read pri_linha
    echo "Informe a linha final: "
    read seg_linha
}    

op=1
while [ ! $op -eq 0 ]
do
    echo "##### Manipulando arquivos com SED / Acesso SSH #####"
    echo "1 - Substituir termo (Leitura)"
    echo "2 - Substituir termo (Gravacao)"
    echo "3 - Numerar linhas"
    echo "4 - Remover numeracao linhas"
    echo "5 - Imprimir intervalo"
    echo "6 - Imprimir linha"
    echo "7 - Adcionar termo ao final da linha"
    echo "8 - Remover linha"
    echo "9 - Acesso SSH"
    echo "0 - SAIR"
    echo -n "Informe uma opcao: "
    read op

    clear

    case $op in 
        1)
            echo "Substituir modo leitura"
            ler_termos
            cat $ARQUIVO | sed "s/$termo/$subs/"
        ;;
        2)
            echo "Substituir modo gravacao"
            ler_termos
            sed -i "s/$termo/$subs/" $ARQUIVO
            cat $ARQUIVO
        ;;
        3)
            echo "Numerar linhas"
            linhas=$(wc -l < $ARQUIVO)
            for i in $(seq 1 $linhas)
            do 
                sed -i $i"s/^/$i - /" $ARQUIVO
            done            
            cat $ARQUIVO
        ;;
        4)
            echo "Remover numeracao"
            sed -i 's/^[0-9]*\ -\ //g' $ARQUIVO
            cat $ARQUIVO
        ;;
        5)
            echo "Imprimir intervalo"
            ler_intervalo     
            sed -n $pri_linha,$seg_linha'p' $ARQUIVO
        ;;
        6)
            echo "Imprimir linha"
            echo "Informe a linha: "
            read linha
            sed -n $linha'p' $ARQUIVO            
        ;;
        7)
            echo "Adcionar termo ao final da linha"
            echo "Informe o termo: "
            read termo
            echo "Informe a linha: "
            read linha
            sed -i $linha"s/$/\ - $termo/" $ARQUIVO
            cat $ARQUIVO
        ;;
        8)
            echo "Remover linha"
            echo "Informe a linha: "
            read linha
            sed -i $linha'd' $ARQUIVO
            cat $ARQUIVO
        ;;
        9)
            echo "Acesso SSH"
            echo -n "Informe o ip: "
            read ip
            echo -n "Informe o usuario: "
            read usuario
            ssh $usuario@$ip
        ;;
        0)
            echo "Saindo..."
        ;;
        *)
            echo "Opcao invalida"
    esac
done

