$x = ""
$y = ""
while true
  def input
    puts "------ Insira o valor em binário ------\n"
    print "Digite uma palavra de 11 dígitos binários: "
    entrada = gets.chomp
    verifica_palavra(entrada)
  end  
  
  def verifica_palavra(binario_string)
    if binario_string.length == 11
      operacoes(binario_string)
    else
      puts "Insira uma palavra válida"
      exit 1
    end
  end  
  
  def operacoes(binario_string)
    opcode = binario_string[0, 3]
    # operando = binario_string[3, 11]
    if opcode == "000"
      puts "Complemento de 1 do operando"
      valor = complemento1(binario_string)
      $x = valor
    elsif opcode == "001"
      puts "\nAdição do operando"
      valor = adicao(binario_string)
      $x = valor
    elsif opcode == "010"
      puts "\nAdição imediata"
      valor = adicao_imediata(binario_string)
      $x = valor
    elsif opcode == "011"
      puts "\nSubtração do operando"
      valor = subtracao(binario_string)
      $x = valor
    elsif opcode == "100"
      puts "Subtração imediata do operando"
      valor = subtracao_imediata(binario_string)
      $x = valor
    elsif opcode == "101"
      puts "Leitura"
      valor = leitura_binario(binario_string)
      $x = valor
    elsif opcode == "110"
      puts "Armazena"
      valor = armazena_binario(binario_string)
      $x = valor
    elsif opcode == "111"
      puts "Transferência"
      valor = transfere_variavel(binario_string) 
    end
    mostra_resultado(valor)  
  end  
  
  def complemento1(binario_string)
    operando = binario_string[3, 11]
    res = ""
    for i in 0..7 
      if operando[i] == "0"
        res = res + "1"
      else operando[i] == "1"
        res = res + "0"
      end
    end 
    return res
  end
  
  def adicao(binario_string)
    res = ""
    operando = binario_string[3, 11]
    primeira_parte = operando[0,4]
    segunda_parte = operando[4,8]
    inteiro_um = primeira_parte.to_i(2)
    inteiro_dois = segunda_parte.to_i(2)
    soma = inteiro_dois + inteiro_um
    res = soma.to_s(2)
    return res.rjust(9, '0')
  end  
  
  def adicao_imediata(binario_string)
    res = ""
    operando = binario_string[3, 11]
    inteiro = operando.to_i(2)
    soma = $x.to_i(2) + inteiro
    res = soma.to_s(2)
    return res.rjust(9, '0')
  end  
  
  def subtracao(binario_string)
    res = ""
    operando = binario_string[3, 11]
    primeira_parte = operando[0,4]
    segunda_parte = operando[4,8]
    inteiro_um = primeira_parte.to_i(2)
    inteiro_dois = segunda_parte.to_i(2)
    if inteiro_um > inteiro_dois
      subtracao = inteiro_um - inteiro_dois
      res = subtracao.to_s(2)
    elsif inteiro_dois > inteiro_um
      subtracao = inteiro_dois - inteiro_um
      res = subtracao.to_s(2)
    end
    return res.rjust(9, '0')
  end  
  
  def subtracao_imediata(binario_string)
    res = ""
    operando = binario_string[3, 11]
    inteiro = operando.to_i(2)
    subt = $x.to_i(2) - inteiro
    res = subt.to_s(2)
    return res.rjust(9, '0')
  end
  
  def leitura_binario(binario_string)
    return binario_string
  end  
  
  def armazena_binario(binario_string)
    operando = binario_string[3, 11]
    $x = operando
    return $x
  end
  
  def transfere_variavel(binario_string)
    $y = $x
    return $y
  end  
  
  def mostra_resultado(valor)
    puts "O resultado da operação escolhida é #{valor}!"
    puts $x
    puts $y
  end
  
  
    
    
  
  input
end
