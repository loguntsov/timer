object ConfigForm: TConfigForm
  Left = 226
  Top = 193
  BorderStyle = bsToolWindow
  Caption = 'Опции '
  ClientHeight = 196
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 189
    Height = 13
    Caption = 'Путь к контроллируемой программе:'
  end
  object ExecFileName: TEdit
    Left = 8
    Top = 24
    Width = 265
    Height = 21
    TabOrder = 0
    Text = 'C:\Program Files\Internet Explorer\IEXPLORE.exe'
    OnChange = ExecFileNameChange
  end
  object Button1: TButton
    Left = 280
    Top = 24
    Width = 81
    Height = 25
    Caption = 'Обзор...'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 256
    Top = 160
    Width = 105
    Height = 25
    Caption = 'Ок'
    TabOrder = 2
    OnClick = Button2Click
  end
  object StartMode: TCheckBox
    Left = 8
    Top = 56
    Width = 345
    Height = 17
    Caption = 'Показывать при  нажатии на кнопку ПУСК'
    Checked = True
    State = cbChecked
    TabOrder = 3
    OnClick = StartModeClick
  end
  object AutoDel: TCheckBox
    Left = 8
    Top = 80
    Width = 345
    Height = 17
    Caption = 'Отрубать программу без предупреждения'
    TabOrder = 4
    OnClick = AutoDelClick
  end
  object AutoShutDown: TCheckBox
    Left = 8
    Top = 104
    Width = 345
    Height = 17
    Caption = 'При срабатывании выключать компьютер'
    TabOrder = 5
    OnClick = AutoShutDownClick
  end
  object MessageShutDown: TCheckBox
    Left = 8
    Top = 128
    Width = 345
    Height = 17
    Caption = 'Выключать компьютер без предупреждения'
    TabOrder = 6
    OnClick = MessageShutDownClick
  end
  object Button3: TButton
    Left = 40
    Top = 160
    Width = 69
    Height = 25
    Caption = 'Помощь'
    TabOrder = 7
    OnClick = Button3Click
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.exe'
    Filter = '*.exe|*.exe'
    Left = 8
    Top = 160
  end
end
