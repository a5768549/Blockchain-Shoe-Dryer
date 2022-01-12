const { Router } = require("express");
const {
    updateData,
    listData,
} = require("../services/control");

/** 排程路由 */
const ControlRouter = Router();

ControlRouter.get("/", listData);
ControlRouter.put("/", updateData);

module.exports = ControlRouter;
