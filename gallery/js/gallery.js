/**
 *
 *
 */
function initGalleryByIndex(index) {
    const divs = ["gallery-one", "gallery-two", "gallery-three"];
    var gallery_two = document.getElementById(divs[index]);

    // 每次初始化时判断是否已经有子元素，如果有，则清空子元素
    if (gallery_two && gallery_two.hasChildNodes()) {
        var element_divs = document.getElementsByName("gallery-grid-item-" + index);
        if (element_divs && element_divs.length > 0) {
            for (var i = element_divs.length - 1; i >= 0; i--) {
                gallery_two.removeChild(element_divs[i]);
            }
        }

    }

    var gallerys = gallery_pic[index];
    for (var i = 0; i< gallerys.length; i++) {
        var grid_item_div = document.createElement("div");
        grid_item_div.setAttribute("class", "grid-item");
        grid_item_div.setAttribute("name", "gallery-grid-item-" + index);

        var figure = document.createElement("figure");
        figure.setAttribute("class", "effect-sadie");

        var img = document.createElement("img");
        img.setAttribute("src", gallerys[i].src == "" ? gallerys[i].href : gallerys[i].src);
        img.setAttribute("alt", gallerys[i].alt);
        img.setAttribute("class", "img-fluid tm-img");

        var figcaption = document.createElement("figcaption");

        var h2 = document.createElement("h2");
        h2.setAttribute("class", "tm-figure-title");
        var tm_figure_title = gallerys[i].tm_figure_title == "" ? "" : gallerys[i].tm_figure_title;
        h2.innerHTML = "<span><strong>" + tm_figure_title + "</strong></span>";

        var p = document.createElement("p");
        p.setAttribute("class", "tm-figure-description");
        p.innerText = gallerys[i].tm_figure_description == "" ? "" : gallerys[i].tm_figure_description;

        var a = document.createElement("a");
        a.setAttribute("href", gallerys[i].href);
        a.innerText = gallerys[i].text;

        figcaption.appendChild(h2);
        figcaption.appendChild(p);
        figcaption.appendChild(a);

        figure.appendChild(img);
        figure.appendChild(figcaption);

        grid_item_div.appendChild(figure);
        gallery_two.appendChild(grid_item_div);

    }

}

