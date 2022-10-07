import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id : root;
    objectName: "objTumbler"
    height: 300;
    rotation: 90
    width: 120;
    property string curSelectedFont: "";//当前选中的字体
    // 自定义字体选择更改事件的信号
    signal onvalueChanged(string str);
    //设置某字体，然后根据调整列表中当前选中项为当前字体
    function setFont(newFont){
        tumbler.changeIndexByFont(newFont);

    }
    Tumbler {
        id:tumbler
        x: 0
        y: 0
        width: 120
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        model:DesignBLL.getModel();
        //rotation:90//顺时针旋转90度。
        visibleItemCount:5
        // 列表背景
        background: Item {
            Rectangle {

                opacity: tumbler.enabled ? 0.9 : 1
                border.color: "#000000"
                width: tumbler.width
                height: tumbler.height
                anchors.top: parent.top
                color: "black";
                radius: 5;
            }
        }
        //具体Item的代理
        delegate: Rectangle{
            opacity: 1.0 - Math.abs(Tumbler.displacement) / (tumbler.visibleItemCount / 2) // 这行代码控制列表上下的item透明度逐渐降低，渐隐效果
            color : tumbler.currentIndex === index ? "darkred" : "transparent";// 根据是否当前选中item调整背景色
                Text {
                    anchors.fill: parent
                    text: model.modelData.listData;      // item显示的文字使用fontListModel的displayData
                    rotation:270//顺时针旋转30度。
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                    font.bold: tumbler.currentIndex === index; // 根据是否当前选中item调整字体是否加粗
                    font.pointSize: tumbler.currentIndex === index ? 24 : 14;// 根据是否当前选中item调整字体大小
                    color: tumbler.currentIndex === index ? "lightblue" : "white";// 根据是否当前选中item调整字体颜色
                }
        }
        // 当前选中项更改事件
        onCurrentIndexChanged: {
            //console.log(tumbler.model[tumbler.currentIndex].listData);
            onvalueChanged(tumbler.model[tumbler.currentIndex].listData);//向外发信号
        }
        // 根据字体名称设置当前选中的item,遍历Model,数据对比
        function changeIndexByFont(fontName){
            for(var i = 0; i < tumbler.count; ++i){
                if(tumbler.model[i].listData === fontName){
                    tumbler.currentIndex = i;
                    break;
                }
            }
        }
    }
}
