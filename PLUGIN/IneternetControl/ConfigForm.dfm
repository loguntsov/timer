object ConfigF: TConfigF
  Left = 193
  Top = 185
  BorderStyle = bsDialog
  Caption = 'Настройка ...'
  ClientHeight = 227
  ClientWidth = 192
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010002002020100000000000E80200002600000010101000000000002801
    00000E0300002800000020000000400000000100040000000000800200000000
    0000000000000000000000000000000000000000800000800000008080008000
    0000800080008080000080808000C0C0C0000000FF0000FF000000FFFF00FF00
    0000FF00FF00FFFF0000FFFFFF00000000000000000000000000000000000000
    0077700000000000000777000000000007000000000000000000007000000000
    7000770000000000007700070000000000070000000000000000700000000000
    00000000008F07700000000000000000000000008F08F0000000000000000000
    0000008F08F0808877000000000000000000FF08F08F08F00000000000000000
    00000FF08F008FFF88770000000000000000F008008FFFF80000000000000000
    000FFFFFFFFFFF808888000000000000008FFFFF80008808FFF8700000000000
    608FFFFF0FF8008FFFFF8707000000066088FFFFF0FFFFFFFFFFF0880700000E
    66088FFFFF0FFFFFFFFF0BB07770060E666088000000000007F0BB0787776660
    E666000000000000000BB078787766660E6660000000000000BB088787876666
    60EE0000000000000700F888787866666600000000000000007F8F8887806666
    66000000000000000008F8F8887066666600000000000000000F8F8F88800666
    60000000000000000000F8F8F8000666600000000000000000008F8F8F000666
    0000000000000000000008F8F0000066000000000000000000000F8F80000060
    0000000000000000000000F80000006000000000000000000000008000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000FFFFFFFFFC7FFE3FFBFFFFDFF73FFCEFFEFC
    1F7FFFF00FFFFFC003FFFF0001FFFE0000FFFE00007FFE00007FFC00007FF000
    000FE0000003C00000018000000000000000003FF800003FF800007FF80000FF
    F80101FFFC0101FFFC0183FFFE0383FFFE0387FFFF07C7FFFF07CFFFFF8FCFFF
    FF9FFFFFFFFFFFFFFFFFFFFFFFFF280000001000000020000000010004000000
    0000C00000000000000000000000000000000000000000000000000080000080
    00000080800080000000800080008080000080808000C0C0C0000000FF0000FF
    000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0000077000000770000070
    00000000070000000000000000000000007F7F0000000000F7FFF7FF00000000
    7FF0FF0000000008FF0F00FF80000E608FF0FFF8080060E600000000B077660E
    6000000B07876660000000008878666000000000F8876600000000008F800000
    0000000008F000000000000000000000000000000000E7E70000DFFB0000FC3F
    0000F00F0000E0070000E007000080010000000000000000000003C0000007C0
    00000FE000001FE10000BFF10000BFFB0000FFFF0000}
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label8: TLabel
    Left = 4
    Top = 176
    Width = 127
    Height = 13
    Caption = 'В день тратить не более '
  end
  object GroupBox1: TGroupBox
    Left = 4
    Top = 8
    Width = 185
    Height = 161
    Caption = 'Тарифная политика, руб/час'
    TabOrder = 0
    object Label1: TLabel
      Left = 4
      Top = 24
      Width = 33
      Height = 13
      Caption = '00:00 -'
    end
    object Label2: TLabel
      Left = 4
      Top = 44
      Width = 33
      Height = 13
      Caption = '00:00 -'
    end
    object Label3: TLabel
      Left = 4
      Top = 68
      Width = 33
      Height = 13
      Caption = '00:00 -'
    end
    object Label4: TLabel
      Left = 4
      Top = 92
      Width = 33
      Height = 13
      Caption = '00:00 -'
    end
    object Label5: TLabel
      Left = 4
      Top = 116
      Width = 33
      Height = 13
      Caption = '00:00 -'
    end
    object Label6: TLabel
      Left = 4
      Top = 140
      Width = 33
      Height = 13
      Caption = '00:00 -'
    end
    object Label7: TLabel
      Left = 52
      Top = 140
      Width = 27
      Height = 13
      Caption = '24:00'
    end
    object ComboBox1: TComboBox
      Left = 40
      Top = 16
      Width = 53
      Height = 22
      Style = csOwnerDrawFixed
      ItemHeight = 16
      TabOrder = 0
      OnChange = ComboBox1Change
      Items.Strings = (
        '01:00'
        '02:00'
        '03:00'
        '04:00'
        '05:00'
        '06:00'
        '07:00'
        '08:00'
        '09:00'
        '10:00'
        '11:00'
        '12:00'
        '13:00'
        '14:00'
        '15:00'
        '16:00'
        '17:00'
        '18:00'
        '19:00'
        '20:00'
        '21:00'
        '22:00'
        '23:00'
        '24:00')
    end
    object Edit1: TEdit
      Left = 104
      Top = 16
      Width = 73
      Height = 21
      TabOrder = 1
    end
    object ComboBox2: TComboBox
      Left = 40
      Top = 40
      Width = 53
      Height = 22
      Style = csOwnerDrawFixed
      ItemHeight = 16
      TabOrder = 2
      OnChange = ComboBox2Change
      Items.Strings = (
        '01:00'
        '02:00'
        '03:00'
        '04:00'
        '05:00'
        '06:00'
        '07:00'
        '08:00'
        '09:00'
        '10:00'
        '11:00'
        '12:00'
        '13:00'
        '14:00'
        '15:00'
        '16:00'
        '17:00'
        '18:00'
        '19:00'
        '20:00'
        '21:00'
        '22:00'
        '23:00'
        '24:00')
    end
    object Edit2: TEdit
      Left = 104
      Top = 40
      Width = 73
      Height = 21
      TabOrder = 3
    end
    object ComboBox3: TComboBox
      Left = 40
      Top = 64
      Width = 53
      Height = 22
      Style = csOwnerDrawFixed
      ItemHeight = 16
      TabOrder = 4
      OnChange = ComboBox3Change
      Items.Strings = (
        '01:00'
        '02:00'
        '03:00'
        '04:00'
        '05:00'
        '06:00'
        '07:00'
        '08:00'
        '09:00'
        '10:00'
        '11:00'
        '12:00'
        '13:00'
        '14:00'
        '15:00'
        '16:00'
        '17:00'
        '18:00'
        '19:00'
        '20:00'
        '21:00'
        '22:00'
        '23:00'
        '24:00')
    end
    object Edit3: TEdit
      Left = 104
      Top = 64
      Width = 73
      Height = 21
      TabOrder = 5
    end
    object ComboBox4: TComboBox
      Left = 40
      Top = 88
      Width = 53
      Height = 22
      Style = csOwnerDrawFixed
      ItemHeight = 16
      TabOrder = 6
      OnChange = ComboBox4Change
      Items.Strings = (
        '01:00'
        '02:00'
        '03:00'
        '04:00'
        '05:00'
        '06:00'
        '07:00'
        '08:00'
        '09:00'
        '10:00'
        '11:00'
        '12:00'
        '13:00'
        '14:00'
        '15:00'
        '16:00'
        '17:00'
        '18:00'
        '19:00'
        '20:00'
        '21:00'
        '22:00'
        '23:00'
        '24:00')
    end
    object Edit4: TEdit
      Left = 104
      Top = 88
      Width = 73
      Height = 21
      TabOrder = 7
    end
    object ComboBox5: TComboBox
      Left = 40
      Top = 112
      Width = 53
      Height = 22
      Style = csOwnerDrawFixed
      ItemHeight = 16
      TabOrder = 8
      OnChange = ComboBox5Change
      Items.Strings = (
        '01:00'
        '02:00'
        '03:00'
        '04:00'
        '05:00'
        '06:00'
        '07:00'
        '08:00'
        '09:00'
        '10:00'
        '11:00'
        '12:00'
        '13:00'
        '14:00'
        '15:00'
        '16:00'
        '17:00'
        '18:00'
        '19:00'
        '20:00'
        '21:00'
        '22:00'
        '23:00'
        '24:00')
    end
    object Edit5: TEdit
      Left = 104
      Top = 112
      Width = 73
      Height = 21
      TabOrder = 9
    end
    object Edit6: TEdit
      Left = 104
      Top = 136
      Width = 73
      Height = 21
      TabOrder = 10
    end
  end
  object Edit7: TEdit
    Left = 132
    Top = 172
    Width = 45
    Height = 21
    TabOrder = 1
    Text = '15'
  end
  object BitBtn1: TBitBtn
    Left = 4
    Top = 196
    Width = 75
    Height = 25
    TabOrder = 2
    Kind = bkOK
  end
end
