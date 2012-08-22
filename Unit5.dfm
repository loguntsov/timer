object Form5: TForm5
  Tag = 11
  Left = 202
  Top = 122
  BorderStyle = bsDialog
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' ...'
  ClientHeight = 300
  ClientWidth = 309
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  ShowHint = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Page: TPageControl
    Tag = 11
    Left = 0
    Top = 0
    Width = 309
    Height = 300
    ActivePage = TabOptions
    Align = alClient
    DockSite = True
    HotTrack = True
    ParentShowHint = False
    ShowHint = True
    TabIndex = 2
    TabOrder = 0
    object TabSetup: TTabSheet
      Tag = 11
      Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072
      object LangGroupBox: TGroupBox
        Tag = 11
        Left = 8
        Top = 4
        Width = 289
        Height = 49
        Hint = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1103#1079#1099#1082#1072
        Caption = #1071#1079#1099#1082
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        object ButLanguage: TButton
          Left = 8
          Top = 16
          Width = 177
          Height = 21
          Hint = #1042#1099#1073#1086#1088' '#1076#1088#1091#1075#1086#1075#1086' '#1103#1079#1099#1082#1072' '#1076#1083#1103' '#1090#1072#1084#1077#1088#1072
          Caption = #1053#1077#1090
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = ButLanguageClick
        end
        object Button5: TButton
          Left = 188
          Top = 16
          Width = 93
          Height = 21
          Hint = #1042#1099#1073#1086#1088' '#1089#1090#1072#1085#1076#1072#1088#1090#1085#1086#1075#1086' '#1056#1059#1057#1057#1050#1054#1043#1054' '#1103#1079#1099#1082#1072
          Caption = 'Russian'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = Button5Click
        end
      end
      object ButAddDesktop: TButton
        Tag = 11
        Left = 16
        Top = 60
        Width = 277
        Height = 25
        Hint = #1069#1090#1072' '#1082#1085#1086#1087#1082#1072' '#1076#1086#1073#1072#1074#1083#1103#1077#1090' '#1103#1088#1083#1099#1082' '#1058#1072#1081#1084#1077#1088#1072' '#1085#1072' '#1088#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1072' '#1088#1072#1073#1086#1095#1080#1081' '#1089#1090#1086#1083
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = ButAddDesktopClick
      end
      object ButAddQuickLaunch: TButton
        Tag = 11
        Left = 16
        Top = 92
        Width = 277
        Height = 25
        Hint = 
          #1069#1090#1072' '#1082#1085#1086#1087#1082#1072' '#1076#1086#1073#1072#1074#1083#1103#1077#1090' '#1080#1082#1086#1085#1082#1091' '#1058#1072#1081#1084#1077#1088#1072' '#1074' '#1087#1072#1085#1077#1083#1100' '#1073#1099#1089#1090#1088#1086#1082#1086' '#1079#1072#1087#1091#1089#1082#1072' ('#1090 +
          #1086#1083#1100#1082#1086' '#1076#1083#1103' Win98 '#1080' '#1089#1090#1072#1088#1096#1077')'
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1087#1072#1085#1077#1083#1100' '#1079#1072#1087#1091#1089#1082#1072
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = ButAddQuickLaunchClick
      end
      object ButAddStartMenu: TButton
        Tag = 11
        Left = 16
        Top = 124
        Width = 277
        Height = 25
        Hint = #1044#1086#1073#1072#1074#1083#1103#1077#1090' '#1080#1082#1086#1085#1082#1091' '#1058#1072#1081#1084#1077#1088#1072' '#1074' '#1084#1077#1085#1102' '#1055#1091#1089#1082
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1084#1077#1085#1102' '#1055#1091#1089#1082
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = ButAddStartMenuClick
      end
    end
    object TabSkins: TTabSheet
      Tag = 11
      Caption = #1057#1082#1080#1085#1099
      ImageIndex = 1
      object SkinPage: TPageControl
        Left = 0
        Top = 0
        Width = 301
        Height = 272
        ActivePage = tabSkinsInFile
        Align = alClient
        Style = tsButtons
        TabIndex = 1
        TabOrder = 0
        object tabSkinsInFolder: TTabSheet
          Tag = 11
          Caption = #1042' '#1082#1072#1090#1072#1083#1086#1075#1072#1093
          object SkinBox: TListBox
            Left = 0
            Top = 0
            Width = 293
            Height = 241
            Align = alClient
            ItemHeight = 13
            Items.Strings = (
              #1057#1090#1072#1085#1076#1072#1088#1090#1085#1099#1081)
            PopupMenu = pmSkinsInFolder
            TabOrder = 0
            OnClick = SkinBoxClick
          end
        end
        object tabSkinsInFile: TTabSheet
          Tag = 11
          Caption = #1042' '#1092#1072#1081#1083#1072#1093
          ImageIndex = 1
          object FileSkinBox: TListBox
            Left = 0
            Top = 0
            Width = 293
            Height = 241
            Align = alClient
            ItemHeight = 13
            PopupMenu = pmSkinsInFile
            TabOrder = 0
            OnClick = FileSkinBoxClick
          end
        end
      end
    end
    object TabOptions: TTabSheet
      Tag = 11
      Caption = #1054#1087#1094#1080#1080
      ImageIndex = 2
      object butBrowse: TButton
        Tag = 11
        Left = 28
        Top = 40
        Width = 105
        Height = 21
        Caption = #1042#1099#1073#1086#1088' '#1092#1072#1081#1083#1072' ...'
        TabOrder = 0
        OnClick = butBrowseClick
      end
      object ckbAlwaysOnTop: TCheckBox
        Tag = 11
        Left = 8
        Top = 80
        Width = 285
        Height = 17
        Caption = #1042#1089#1077#1075#1076#1072' '#1087#1086#1074#1077#1088#1093' '#1076#1088#1091#1075#1080#1093' '#1086#1082#1086#1085
        TabOrder = 1
        OnClick = ckbAlwaysOnTopClick
      end
      object ckbMessage: TCheckBox
        Tag = 11
        Left = 8
        Top = 4
        Width = 289
        Height = 17
        Caption = #1042#1099#1074#1086#1076#1080#1090#1100' '#1089#1086#1086#1073#1097#1077#1085#1080#1077' '#1086' '#1080#1089#1090#1077#1095#1077#1085#1080#1080' '#1074#1088#1077#1084#1077#1085#1080
        Checked = True
        State = cbChecked
        TabOrder = 2
        OnClick = ckbMessageClick
      end
      object ckbPlayMusic: TCheckBox
        Tag = 11
        Left = 8
        Top = 24
        Width = 285
        Height = 13
        Caption = #1048#1075#1088#1072#1090#1100' '#1084#1091#1079#1099#1082#1091' '#1082#1086#1075#1076#1072' '#1074#1088#1077#1084#1103' '#1080#1089#1090#1077#1082#1083#1086
        Checked = True
        State = cbChecked
        TabOrder = 3
        OnClick = ckbPlayMusicClick
      end
      object ckbMinimizeInSysTray: TCheckBox
        Tag = 11
        Left = 8
        Top = 64
        Width = 285
        Height = 13
        Caption = #1052#1080#1085#1080#1084#1080#1079#1080#1088#1086#1074#1072#1090#1100' '#1074' SysTray'
        TabOrder = 4
        OnClick = ckbMinimizeInSysTrayClick
      end
      object rgForAlert: TRadioGroup
        Left = 4
        Top = 100
        Width = 293
        Height = 105
        Caption = #1055#1088#1080' '#1089#1088#1072#1073#1072#1090#1099#1074#1072#1085#1080#1080':'
        ItemIndex = 0
        Items.Strings = (
          #1053#1080#1095#1077#1075#1086' '#1085#1077' '#1076#1077#1083#1072#1090#1100
          #1042#1099#1082#1083#1102#1095#1072#1090#1100' '#1082#1086#1084#1087#1100#1102#1090#1077#1088
          #1047#1072#1089#1099#1087#1072#1090#1100
          #1044#1088#1091#1075#1086#1077':')
        TabOrder = 5
        OnClick = rgForAlertClick
      end
      object eOther: TEdit
        Left = 76
        Top = 176
        Width = 213
        Height = 21
        Enabled = False
        TabOrder = 6
      end
    end
    object TabPlugin: TTabSheet
      Tag = 11
      Caption = #1055#1083#1072#1075#1080#1085#1099
      ImageIndex = 3
      object PluginList: TCheckListBox
        Left = 4
        Top = 8
        Width = 225
        Height = 233
        ItemHeight = 13
        TabOrder = 0
      end
      object butAddPlug: TBitBtn
        Tag = 11
        Left = 236
        Top = 152
        Width = 61
        Height = 21
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        TabOrder = 1
        OnClick = butAddPlugClick
      end
      object butDelPlug: TBitBtn
        Tag = 11
        Left = 236
        Top = 176
        Width = 61
        Height = 21
        Caption = #1059#1076#1072#1083#1080#1090#1100
        TabOrder = 2
        OnClick = butDelPlugClick
      end
      object butPlugUp: TBitBtn
        Tag = 11
        Left = 236
        Top = 12
        Width = 61
        Height = 21
        Caption = #1042#1074#1077#1088#1093
        TabOrder = 3
        OnClick = butPlugUpClick
      end
      object butPlugDown: TBitBtn
        Tag = 11
        Left = 236
        Top = 40
        Width = 61
        Height = 21
        Caption = #1042#1085#1080#1079
        TabOrder = 4
        OnClick = butPlugDownClick
      end
      object butPlugAbiut: TBitBtn
        Tag = 11
        Left = 8
        Top = 248
        Width = 81
        Height = 21
        Caption = #1054' '#1087#1083#1072#1075#1080#1085#1077' ...'
        TabOrder = 5
        OnClick = butPlugAbiutClick
      end
      object butPlagConfig: TBitBtn
        Tag = 11
        Left = 112
        Top = 248
        Width = 97
        Height = 21
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' ...'
        TabOrder = 6
        OnClick = butPlagConfigClick
      end
    end
  end
  object OpenDialogForSetup: TOpenDialog
    DefaultExt = '*.ini'
    Filter = '*.ini|*.ini'
    Left = 4
    Top = 296
  end
  object OpenDialogForPlay: TOpenDialog
    Filter = '*.wav|*.wav|*.mp3|*.mp3|*.*|*.*'
    FilterIndex = 3
    Left = 32
    Top = 292
  end
  object pmAddPlug: TPopupMenu
    AutoHotkeys = maManual
    AutoLineReduction = maManual
    Left = 4
    Top = 292
  end
  object pmSkinsInFolder: TPopupMenu
    Left = 80
    Top = 291
    object mnuSaveSkinToFile: TMenuItem
      Caption = 'C'#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1086#1076#1085#1086#1084' '#1092#1072#1081#1083#1077
      OnClick = mnuSaveSkinToFileClick
    end
  end
  object pmSkinsInFile: TPopupMenu
    Left = 128
    Top = 283
    object mnuSaveSkinToFolder: TMenuItem
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082' '#1082#1072#1090#1072#1083#1086#1075
    end
  end
  object dlgSaveSkinToFile: TSaveDialog
    DefaultExt = '*.TSK'
    Filter = '*.TSK|*.TSK'
    Left = 164
    Top = 288
  end
end
