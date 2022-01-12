/** 全域變數 */
globalThis.apiUrl = "http://127.0.0.1:3000/api/";
var apiUrl = globalThis.apiUrl;

///get request and render status
try {
    fetch(apiUrl + "control")
        .then((res) => {
            return res.json();
        })
        .then((result) => {
            let c1 = document.getElementById("c1");
            let c2 = document.getElementById("c2");
            let c3 = document.getElementById("c3");
            let c4 = document.getElementById("c4");
            result.forEach((element) => {
                let div = document.createElement("div");
                let status = "";
                element.status ? (status = "運行中") : (status = "停止運轉");
                div.append("第" + element.ID + "台：" + status);

                if (element.ID === 1) c1.append(div);
                if (element.ID === 2) c2.append(div);
                if (element.ID === 3) c3.append(div);
                if (element.ID === 4) c4.append(div);
            });
        });
} catch (error) {
    console.log(error);
}
