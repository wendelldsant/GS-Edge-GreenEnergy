Edge: Solar Tracker Project 🌞🌱
Edge é um projeto de rastreador solar desenvolvido para otimizar sistemas de captação de energia solar, explorando conceitos de energia limpa no tema Green Energy proposto pela avaliação Global Solution.

Este repositório contém:

O código-fonte em Arduino para controle do rastreador.
O fluxo Node-RED para monitoramento e visualização.
📌 Sobre o Projeto
O rastreador solar utiliza:

4 sensores LDR para medir a luminosidade do ambiente.
2 servos para ajustar o painel à posição de máxima incidência solar.
O objetivo é melhorar a eficiência de painéis solares ao garantir alinhamento dinâmico com a luz solar.

📂 Estrutura do Repositório
/src: Código-fonte do firmware em Arduino (C/C++).
/build/arduino.avr.uno: Arquivo .hex do firmware gerado.
/flows-node-red.json: Fluxo do Node-RED para monitoramento.
🚀 Passos para Configuração e Execução
1. Configuração do Firmware no Arduino
Abra o código-fonte na IDE do Arduino.
Selecione a placa Arduino Uno.
Salve o projeto e exporte o binário compilado através do menu:
Sketch > Exportar Binário Compilado.
2. Carregar o Firmware no SimulIDE
No SimulIDE, abra o circuito do rastreador solar.
Navegue até a pasta build/arduino.avr.uno no repositório.
Carregue o arquivo .hex no Arduino simulado.
3. Simulação da Comunicação Serial
Instale o com0com ou Launch Virtual Serial Port Driver para criar portas COM virtuais (por exemplo, COM1 e COM2 como par).
Configure o SimulIDE para usar as portas COM simuladas.
4. Configuração do MQTT no HiveMQ
Acesse o site do HiveMQ.
Inscreva-se no tópico MQTT:
bash
Copiar código
globalsolution/medicoes_solarTracker_Wendell_1ESR_2024  
5. Configuração do Node-RED
Abra o Node-RED.
Importe o arquivo flows-node-red.json disponível no repositório.
Clique em Deploy para aplicar as configurações.
6. Testes e Visualização
No SimulIDE, ajuste os valores dos sensores LDR.
Observe os dados atualizados no Node-RED Dashboard e no HiveMQ simultaneamente.
🔧 Requisitos do Projeto
IDE do Arduino para compilar e exportar o firmware.
SimulIDE para simulação do circuito e carregamento do firmware.
com0com ou Launch Virtual Serial Port Driver para simulação de portas COM.
HiveMQ para gerenciamento do tópico MQTT.
Node-RED para visualização e monitoramento.
📜 Licença
Este projeto é licenciado sob a licença MIT. Consulte o arquivo LICENSE para mais informações.

Desenvolvido por Wendell - RM558859 - Engenharia de Software (FIAP, 2024)