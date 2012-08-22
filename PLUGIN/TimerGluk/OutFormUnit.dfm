object OutForm: TOutForm
  Left = 226
  Top = 172
  BiDiMode = bdLeftToRight
  BorderIcons = []
  BorderStyle = bsNone
  ClientHeight = 75
  ClientWidth = 124
  Color = clNone
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poDefaultPosOnly
  PrintScale = poNone
  Scaled = False
  OnClick = FormClick
  OnPaint = FormPaint
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 8
    Top = 32
  end
end
