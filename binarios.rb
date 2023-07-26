MODO = 0
def input
  puts "------ Insira o valor em binário ------\n"
  print "Digite uma palavra de 6 dígitos binários: "
  entrada = gets.chomp
  verifica_palavra(entrada)
end  
  

def verifica_palavra(binario_string)
  if binario_string.length == 6
    operacoes(binario_string)
  else
    puts "Insira uma palavra válida"
    exit 1
  end
end  

def operacoes(binario_string)
  decimal = binario_string.to_i(2)
  puts "\nO valor da palavra em decimal é #{decimal}"
  if decimal < 16
    puts "\nA operação escolhida foi complemento de 1"
    valor = complemento1(binario_string)
  elsif decimal < 32
    puts "\nA operação escolhida foi complemento de 2"
    valor = complemento2(binario_string)
  elsif decimal < 48
    puts "\nA operação escolhida foi adição"
    valor = adicao(binario_string)
  else
    puts "\nA operação escolhida foi subtração"
    valor = subtracao(binario_string)
  end
  puts "O resultado da operação escolhida é #{valor}!"
  
end  

def complemento1(binario_string)
  res = ""
  for i in 0..5 
    if binario_string[i] == "0"
      res = res + "1"
    else binario_string[i] == "1"
      res = res + "0"
    end
  end 
  return res
end

def complemento2(binario_string)
  res = ""
  c1 = complemento1(binario_string)
  resdecimal = c1.to_i(2) + 1
  res = resdecimal.to_s(2)
  return res
end  
  
  

def adicao(binario_string)
  res = ""
  primeira_parte = binario_string[0,3]
  segunda_parte = binario_string[3,3]
  inteiro_um = primeira_parte.to_i(2)
  inteiro_dois = segunda_parte.to_i(2)
  soma = inteiro_dois + inteiro_um
  res = soma.to_s(2)
  return res.rjust(6, '0')
end  
  

def subtracao(binario_string)
  res = ""
  primeira_parte = binario_string[0,3]
  segunda_parte = binario_string[3,3]
  inteiro_um = primeira_parte.to_i(2)
  inteiro_dois = segunda_parte.to_i(2)
  if inteiro_um > inteiro_dois
    subtracao = inteiro_um - inteiro_dois
    res = subtracao.to_s(2)
  else
    subtracao = inteiro_dois - inteiro_um
    res = subtracao.to_s(2)
    case MODO
      when 0
        res[0] = '1'
      when 1
        complemento1(res)
      when 2
        complemento2(res)
    end
  end
  return res.rjust(6, '0')
end  
      

input


  




